class Solution {
public:
    int maxArea;
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};

    bool isValid(int x, int y, int m, int n){
        if(x<0 || x>= m || y<0 || y>=n)
            return false;
        return true;
    }

    void dfs(vector<vector<int>>& grid, int row, int col, int m, int n, int &area){
        area++;
        cout<<area<<endl;
        maxArea = max(maxArea, area);

        grid[row][col] = 0;

        for(int dir=0;dir<4;dir++){
            int nRow = row + dx[dir];
            int nCol = col + dy[dir];

            if(isValid(nRow, nCol, m, n) && grid[nRow][nCol] == 1){
                dfs(grid, nRow, nCol, m, n, area);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        maxArea = INT_MIN;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int area = 0;
                if(grid[i][j]==1){
                    dfs(grid, i, j, m, n, area);
                }
            }
        }
        return maxArea == INT_MIN ? 0 : maxArea;
    }
};