class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for(int num: nums)
            st.insert(num);

        int idx = 0, length = 0;

        // for(;idx < nums.size(); idx++){
        //     if(!st.count(nums[idx]-1)){
        //         int streak = 1;
        //         int currEle = nums[idx];
                                
        //         while(st.count(currEle + 1))
        //         {
        //             streak++; // 4
        //             currEle++; //4  
        //         }
        //         length = max(length, streak); 
        //     }
        // }

        for(int num: st){
            if(!st.count(num-1)){
                int streak = 1;
                int currEle = num;

                while(st.count(currEle +1)){
                    currEle++;
                    streak++;
                }
                length = max(length, streak); 
            }
        }
        return length;

    }
};