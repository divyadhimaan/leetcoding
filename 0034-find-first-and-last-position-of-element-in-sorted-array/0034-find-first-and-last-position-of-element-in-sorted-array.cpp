class Solution {
public:

    int findPosition(vector<int> &nums, int target, int low, int high, bool findFirst){
        int res = -1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target){
                res = mid;
                if(findFirst)
                    high = mid-1;
                else
                    low = mid+1;
            }else if(nums[mid]<target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int f = findPosition(nums, target, 0, n-1, true);
        int l = findPosition(nums, target, 0, n-1, false);
        return {f,l};
    }
};