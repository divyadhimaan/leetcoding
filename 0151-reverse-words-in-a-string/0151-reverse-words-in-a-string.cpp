class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp = "";

        for(char c: s){
            if(c == ' '){
                if(temp != ""){
                    words.push_back(temp);
                    temp = "";
                }
            }else{
                temp += c;
            }
        }

        if(temp != "")
            words.push_back(temp);

        string res;
        for(int i=words.size()-1;i>=0;i--){
            res += words[i] + " ";
        }
        res.pop_back();
        
        return res;
    }
};