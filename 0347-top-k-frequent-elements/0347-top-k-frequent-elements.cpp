typedef pair<int,int> pii;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int num: nums){
            mp[num]++;
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq; //min-heap

        for(auto x: mp){
            pq.push({x.second,x.first});
            if(pq.size() > k)
                pq.pop();
        }

        vector<int> res;
        while(!pq.empty()){

            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;

    }
};