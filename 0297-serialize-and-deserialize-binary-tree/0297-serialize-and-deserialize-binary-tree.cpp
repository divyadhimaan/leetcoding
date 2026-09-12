/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        if(!root)
            return str;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node)
                str += to_string(node->val) + ',' ;
            else
                str += "N,";
            if(node){
                q.push(node->left);
                q.push(node->right);
            }
        }
        str.pop_back();
        cout<<str<<endl;
        
        return str;
    }

    TreeNode* createBinaryTree(vector<string> &nodes, int idx)
    {	
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);
        idx++;

        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();	
                
            if(nodes[idx] == "N")
            {
                node->left = NULL;
            }else{
                node->left = new TreeNode(stoi(nodes[idx]));
                q.push(node->left);
            }
            idx++;

            if(nodes[idx] == "N")
            {
                node->right = NULL;
            }else{
                node->right = new TreeNode(stoi(nodes[idx]));
                q.push(node->right);
            }
            idx++;
        }
        return root;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0)
            return NULL;

        vector<string> nodes;
        stringstream ss(data);
        string nodeVal;
        while(getline(ss, nodeVal, ','))
            nodes.push_back(nodeVal);
            
	    return createBinaryTree(nodes, 0);	

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));