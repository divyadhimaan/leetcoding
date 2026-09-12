class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for(int num: nums)
            st.insert(num);

        int length = 0;

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