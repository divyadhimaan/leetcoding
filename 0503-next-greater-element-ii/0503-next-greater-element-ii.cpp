class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();

        vector<int> res(n, -1);

        for(int i = 0; i < 2*n; i++){
            while(!stk.empty() && nums[stk.top()] < nums[i%n]){
                int j = stk.top();
                stk.pop();
                res[j] = nums[i%n];
            }
            if(i<n)
                stk.push(i);
        }
        return res;
    }
};