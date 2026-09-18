/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void buildGraph(TreeNode* root, unordered_map<int,vector<int>> &graph)
    {
        if(!root)
            return;

        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            buildGraph(root->left, graph);
        }

        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            buildGraph(root->right, graph);
        }

        //leaf nodes
        if(graph.find(root->val) == graph.end())
            graph[root->val] = {};
    }

    void dfsDistanceK(
        unordered_map<int,vector<int>> &graph,
        int k,
        int node,
        vector<int> &result,
        vector<bool> &visited
    ){
        if(k==0){
            result.push_back(node);
            return;
        }
        visited[node] = true;

        for(int nextNode: graph[node]){
            if(!visited[nextNode] && k){
                dfsDistanceK(graph, k-1, nextNode, result, visited);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0)
            return {target->val};


        unordered_map<int,vector<int>> graph;
        buildGraph(root, graph);

        vector<int> result;
        vector<bool> visited(graph.size(), false);
        dfsDistanceK(graph, k, target->val, result, visited);
        return result;
    }
};