class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;

        int miniEle = INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[low] <= nums[mid]) // left sorted
            {
                miniEle = min(miniEle, nums[low]);
                low = mid+1;
            }else{
                miniEle = min(miniEle, nums[mid]);
                high = mid-1;
            }
        }
        return miniEle;
    }
};