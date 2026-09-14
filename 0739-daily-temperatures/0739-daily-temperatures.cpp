class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<int> stk; // maintain a monotonic decreasing stack

        for(int i=0;i<n;i++){
            while(!stk.empty() && temperatures[stk.top()] < temperatures[i]){
                int j = stk.top();
                stk.pop();

                res[j] = i - j;
            }

            stk.push(i);
        }
        return res;
    }
};
