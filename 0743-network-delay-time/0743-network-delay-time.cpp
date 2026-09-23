class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> adjList(n);
        for(int i=0;i<times.size();i++){
            int src = times[i][0];
            int dest = times[i][1];
            int wt = times[i][2];

            adjList[src].push_back({dest, wt});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        while(!pq.empty()){
            auto [currTime, currNode] = pq.top();
            pq.pop();

            if(currTime > dist[currNode])
                continue;

            for(auto [nextNode, t]: adjList[currNode]){
                if(currTime + t < dist[nextNode]){
                    dist[nextNode] = currTime + t;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        int timeTaken = 0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX)
                return -1;

            timeTaken = max(timeTaken, dist[i]);
        }

        return timeTaken;
    }
};