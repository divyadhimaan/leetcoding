class Solution {
public:
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};

    bool isValid(int row, int col, int m, int n){
        if(row < 0 || row>=m || col < 0 || col >=n) 
            return false;
        return true;
    }

    void dfs(vector<vector<char>>& grid, int row, int col, int m, int n){
        grid[row][col] = '*';

        for(int dir = 0; dir<4; dir++){
            int nRow = row + dx[dir];
            int nCol = col + dy[dir];

            if(isValid(nRow, nCol, m, n) && grid[nRow][nCol] == '1'){
                dfs(grid, nRow, nCol, m, n);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int numberOfIslands = 0;

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == '1'){
                    dfs(grid, row, col, m, n);
                    numberOfIslands++;
                }
            }
        }
        return numberOfIslands;
    }
};