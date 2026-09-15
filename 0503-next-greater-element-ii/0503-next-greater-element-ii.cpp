class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();

        vector<int> res(n, -1);

        for(int i = 2*n-1; i >= 0; i--){
            while(!stk.empty() && stk.top() <= nums[i%n])
                stk.pop();

            if(!stk.empty() && i<n)
                res[i] = stk.top();

            stk.push(nums[i%n]);
        }
        return res;
    }
};