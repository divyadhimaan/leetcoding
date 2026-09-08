class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = INT_MIN;
        int start = 0;

        unordered_set<char> st;

        for(int end=0;end<n;end++){
            char c = s[end];
            while(st.count(c)){
                st.erase(s[start]);
                start++;
            }
            st.insert(c);
            maxLen = max(maxLen, end-start+1);
        }
        if(maxLen == INT_MIN)
            return 0;

        return maxLen;
    }
};