class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j=1, count = 1;
        while(i < nums.size()){
            if(nums[i] == nums[i-1]){
                count++;
                if(count > 2){
                    i++;
                    continue;
                }
            }
            else{
                count = 1;
            }

            nums[j] = nums[i];
            i++;
            j++;
        }

        nums.resize(j);
        return j;
    }
};