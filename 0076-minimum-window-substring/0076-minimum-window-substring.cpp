class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        unordered_map<char, int> charFreqMap;

        for(char c: t){
            charFreqMap[c]++;
        }

        int startIdx = -1, minLen = INT_MAX, cnt = 0;

        int start = 0;

        for(int end = 0; end<n; end++){
            if(charFreqMap[s[end]]>0) //char was in t
                cnt++;

            charFreqMap[s[end]]--;

            while(cnt == m) //shrink window when all chars from t found
            {
                if(minLen > end-start+1){
                    startIdx = start;
                    minLen = end-start+1;
                }

                charFreqMap[s[start]]++;
                if(charFreqMap[s[start]] > 0){
                    cnt--;
                }
                start++;
            }

        }
        return startIdx == -1 ? "" : s.substr(startIdx, minLen);

    }
};