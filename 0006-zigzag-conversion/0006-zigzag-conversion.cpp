class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(numRows == 1)
            return s;

        string res = "";
        for(int r = 0; r < numRows; r++){
            int inc = (numRows-1) * 2;
            for(int i = r; i < n; i += inc){
                res += s[i];
                if(r > 0 && r < numRows-1 && i + inc - (2*r) < n){
                    res += s[i+inc-(2*r)];
                }
            }
        }
        return res;
    }
};