class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int num:nums)
            st.insert(num);

        int maxLen =0;
        for(int num:st){
            if(!st.count(num-1)){
                int curr = num;
                int streak = 1;

                while(st.count(curr+1)){
                    curr++;
                    streak++;
                }

                maxLen = max(maxLen, streak);
            }
        }
        return maxLen;
    }
};