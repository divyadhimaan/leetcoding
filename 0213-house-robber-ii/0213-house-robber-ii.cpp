class Solution {
public:
    int robUtil(vector<int> &nums, int start, int end){
        int n = end-start+1;

        if(n==0)
            return 0;
        if(n==1)
            return nums[start];

        // vector<int> dp(n, 0);
        // dp[0] = nums[start];
        // dp[1] = max(nums[start], nums[start+1]);
        int prev2 = nums[start];
        int prev = max(nums[start], nums[start+1]);
        int curr;


        for(int i=2; i<n;i++){
            curr = max(prev, nums[start+i] + prev2);
            // dp[i] = max(dp[i-1], nums[start+i] + dp[i-2]);
            prev2 = prev;
            prev = curr;

        }

        return prev;

        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];

        return max(robUtil(nums, 0, n-2), robUtil(nums, 1, n-1));
    }
};