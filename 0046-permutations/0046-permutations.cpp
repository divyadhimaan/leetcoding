class Solution {
public:
    void generatePermutations(vector<int>& nums, int idx, vector<vector<int>> &allPermutations)
    {
        if(idx == nums.size()-1){
            allPermutations.push_back(nums);
            return;
        }

        for(int i=idx;i<nums.size();i++){
            swap(nums[i], nums[idx]);
            generatePermutations(nums, idx+1, allPermutations);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> allPermutations;
        generatePermutations(nums, 0, allPermutations);
        return allPermutations;
    }
};