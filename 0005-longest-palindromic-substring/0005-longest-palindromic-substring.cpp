class Solution {
public:
    string res;
    int resLen;

    void findPalindrome(string s, int start, int end){
        while(start >=0 && end < s.length() && s[start] == s[end])
        {
            int currLen = end-start+1;

            if(currLen > resLen){
                res = s.substr(start, currLen);
                resLen = currLen;
            }
            start--;
            end++;
        }
    }
    string longestPalindrome(string s) {
        int n = s.length();

        for(int i=0;i<n;i++){
            findPalindrome(s, i, i); //odd length
            findPalindrome(s, i, i+1); // even length
        }
        return res;
    }
};