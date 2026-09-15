typedef pair<int,vector<int>> pvi;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pvi> pq;

        for(int i=0;i<n;i++){
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push({dist, {points[i][0], points[i][1]}});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int>> res;
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            res.push_back(x.second);
        }
        return res;
    }
};