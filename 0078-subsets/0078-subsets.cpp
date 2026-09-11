class Solution {
public:
    void findAllSubsets(vector<int>& nums, int idx, vector<int> &curr, vector<vector<int>> &res){
        if(idx == nums.size())
        {
            res.push_back(curr);
            return;
        }
        //not take
        findAllSubsets(nums, idx+1, curr, res);

        //take
        curr.push_back(nums[idx]);
        findAllSubsets(nums, idx+1, curr, res);
        curr.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;

        findAllSubsets(nums, 0, curr, res);
        return res;
    }
};