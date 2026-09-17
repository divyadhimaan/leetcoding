class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> firstSeen;
        int prefixSum = 0, maxLen = INT_MIN;
        firstSeen[0] = -1;

        for(int i = 0; i<n;i++){
            prefixSum += nums[i] == 0 ? -1 : 1;

            if(firstSeen.find(prefixSum) != firstSeen.end())
                maxLen = max(maxLen, i - firstSeen[prefixSum]);
            else
                firstSeen[prefixSum] = i;
        }
        return maxLen == INT_MIN ? 0 : maxLen;
    }
};