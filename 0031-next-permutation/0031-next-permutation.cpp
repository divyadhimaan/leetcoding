class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        
        int pivot = -1;

        //find pivot
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1])
            {
                pivot = i;
                break;
            }
        }

        //if no pivot found - last permutation
        if(pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // find swap for pivot
        for(int i=nums.size()-1;i>=pivot;i--){
            if(nums[i]>nums[pivot]){
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        //sort the array to the right of pivot
        reverse(nums.begin() + pivot+1, nums.end());
    }
};
