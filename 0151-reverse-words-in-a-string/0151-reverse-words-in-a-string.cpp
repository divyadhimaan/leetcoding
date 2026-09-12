class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        string temp = "";
        for(char c: s){
            if(c == ' '){
                if(temp != ""){
                    stk.push(temp);
                    temp = "";
                }
            }else{
                temp += c;
            }
        }
        cout<<"temp: "<<temp<<endl;
        if(temp != "")
            stk.push(temp);
        string res;
        while(!stk.empty()){
            res += stk.top() + " ";
            stk.pop();
        }
        res.pop_back();
        return res;
    }
};