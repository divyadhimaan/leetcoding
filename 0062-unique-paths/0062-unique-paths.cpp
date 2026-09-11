class Solution {
public:
    int uniquePathsUtil(int m, int n, vector<vector<int>> &memo) {
        if(m==0 && n==0)
            return 1;

        if(m<0 || n<0)
            return 0;

        if(memo[m][n] != -1)
            return memo[m][n];

        return memo[m][n] = uniquePathsUtil(m-1, n, memo) + uniquePathsUtil(m, n-1, memo);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int> (n,-1));
        return uniquePathsUtil(m-1, n-1, memo);
    }
};