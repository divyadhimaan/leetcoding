class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int ele1, ele2;

        for(int num: nums)
        {
            if(cnt1 == 0 && num != ele2){
                cnt1++;
                ele1 = num;
            }else if(cnt2 == 0 && num != ele1){
                cnt2++;
                ele2 = num;
            }else if(ele1 == num){
                cnt1++;
            }else if(ele2 == num){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2=0;
        for(int num: nums){
            if(num == ele1)
                cnt1++;
            if(num == ele2)
                cnt2++;
        }

        vector<int> ans;
        if(cnt1 > n/3)
            ans.push_back(ele1);
        if(cnt2 > n/3)
            ans.push_back(ele2);

        return ans;
    }
};