class Solution {
public:
    void dfs(vector<vector<int>> &isConnected, int currNode, vector<bool> &visited){
        visited[currNode] = true;

        for(int nextNode=0;nextNode<isConnected.size();nextNode++)
        {
            if(!visited[nextNode] && isConnected[currNode][nextNode])
                dfs(isConnected, nextNode, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();


        vector<bool> visited(n, false);
        int provinces = 0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(isConnected, i, visited);
                provinces++;
            }
        }
        return provinces;
    }
};