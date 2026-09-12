typedef pair<int,int> pii;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int num: nums){
            mp[num]++;
        }

        vector<vector<int>> buckets(n+1);
        for(auto x: mp){
            buckets[x.second].push_back(x.first);
        }

        vector<int> res;
        for(int i=n;i>=1 && res.size() < k;i--)
        {
            for(int j=0;j<buckets[i].size();j++){
                res.push_back(buckets[i][j]);
            }
        }
        return res;

    }
};