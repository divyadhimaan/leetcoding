class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;

        int coverage = 0, lastIdx = 0, jumps= 0;

        for(int i=0;i<n;i++){
            coverage = max(coverage, nums[i]+i);

            if(i==lastIdx){
                lastIdx = coverage;
                jumps++;

                if(lastIdx >= n-1)
                    break;
            }
        }
        return jumps;
    }
};
