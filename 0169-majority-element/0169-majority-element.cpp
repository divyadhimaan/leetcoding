class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int majEle = -1, majCount= 0;

        for(int i=0;i<n;i++){
            if(majCount == 0){
                majEle = nums[i];
                majCount = 1;
            }

            else if(nums[i]==majEle){
                majCount++;
            }else{
                majCount--;
            }
        }
        return majEle;
    }
};