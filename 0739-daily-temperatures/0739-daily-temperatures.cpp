class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<int> stk; // maintain a monotonic decreasing stack

        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && temperatures[stk.top()] <= temperatures[i]){
                stk.pop();
            }
            if(stk.empty())
                res[i] = 0;
            else
                res[i] = stk.top() - i;

            stk.push(i);
        }
        return res;
    }
};

// 73 - 0
// 76 - 0
// 72 - 1
// 69 - 1
// 71 - 2
// 75 - 4
// 74 - 1
// 73 - 1



// stack -> 76, 75, 74, 73

// maintain a monotonic decreasing stack
// pop until greater in stack