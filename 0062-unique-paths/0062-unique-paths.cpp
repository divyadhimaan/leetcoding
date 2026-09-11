class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> curr(n,1), prev(n,1);
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++){
                curr[j] = prev[j] + curr[j-1];
            }
            prev = curr;
        }
        return curr[n-1];

    }
};