class Solution {
public:
    void dfs(vector<vector<int>> &adjList, int currNode, vector<bool> &visited){
        visited[currNode] = true;

        for(int nextNode: adjList[currNode])
        {
            if(!visited[nextNode])
                dfs(adjList, nextNode, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n);

        //Step 1: Create adjacency list
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j] == 1)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int provinces = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adjList, i, visited);
                provinces++;
            }
        }
        return provinces;
    }
};