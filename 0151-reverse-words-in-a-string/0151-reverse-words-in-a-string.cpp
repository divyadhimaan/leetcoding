class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();

        int w = 0;
        for(int r = 0; r<n;r++){
            if(s[r] != ' '){
                if(w > 0)
                    s[w++] = ' ';
                while(r < n && s[r] != ' ')
                    s[w++] = s[r++];
            }
        }

        s.resize(w);

        reverse(s.begin(), s.end());

        int start = 0;
        for(int i=0;i<=w;i++){
            if(i==w || s[i] == ' ')
            {
                reverse(s.begin()+start, s.begin() +i);
                start = i+1;
            }
        }
        return s;
    }
};