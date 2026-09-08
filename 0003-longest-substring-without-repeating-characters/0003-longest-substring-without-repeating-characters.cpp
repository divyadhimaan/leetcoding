class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = INT_MIN;
        int start = 0;

        unordered_map<char, int> lastSeenIdx;

        for(int end=0;end<n;end++){
            char c = s[end];
            if(lastSeenIdx.find(c) != lastSeenIdx.end()){
                start = max(start, lastSeenIdx[c]+1);
            }
            lastSeenIdx[c] = end;
            maxLen = max(maxLen, end-start+1);
        }
        if(maxLen == INT_MIN)
            return 0;

        return maxLen;
    }
};