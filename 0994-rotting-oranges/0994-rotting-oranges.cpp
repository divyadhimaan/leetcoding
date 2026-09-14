class Solution {
public:
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};

    bool isValid(int x, int y, int m, int n){
        if(x<0 || x>= m || y<0 ||y >=n)
            return false;
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int numFresh = 0;
        int time = -1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    numFresh++;
                else if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }

        if(numFresh==0)
            return 0;

        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                auto [x,y] = q.front();
                q.pop();

                for(int dir=0;dir<4;dir++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if(isValid(nx,ny, m, n) && grid[nx][ny]==1){
                        grid[nx][ny] = 2;
                        numFresh--;
                        q.push({nx,ny});
                    }
                }
            }
            time++;
        }
        return numFresh == 0 ? time : -1;
    }
};