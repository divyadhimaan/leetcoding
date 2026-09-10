class Solution {
public:
    void generateParenthesisUtil(string temp, vector<string> &result, int numberOfOpened, int numberOfClosed, int n){
        if(temp.size()==2*n){
            result.push_back(temp);
            return;
        }
        
        if(numberOfOpened < n){
            generateParenthesisUtil(temp+'(', result, numberOfOpened+1, numberOfClosed, n);
        }
        if(numberOfClosed < numberOfOpened){
            generateParenthesisUtil(temp+')', result, numberOfOpened, numberOfClosed+1, n);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp = "";
        generateParenthesisUtil(temp, result, 0,0, n);
        return result;
    }
};