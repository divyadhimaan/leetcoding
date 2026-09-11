class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        //jumps[i] -> minimum number of jumps to reach index i
        vector<int> jumps(n, INT_MAX);
        jumps[0]=0;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]+j >= i){
                    jumps[i] = min(jumps[i], jumps[j]+1);
                }
            }
        }

        return jumps[n-1];
    }
};
