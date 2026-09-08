class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n==0)
            return {newInterval};

        int idx = 0;

        int low = 0, high = n-1, startIdx = n;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(intervals[mid][1] >= newInterval[0]){
                startIdx = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }


        low = 0, high=n-1;
        int endIdx = -1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(intervals[mid][0] <= newInterval[1]){
                endIdx = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }


        if(startIdx <= endIdx){
            newInterval[0] = min(intervals[startIdx][0], newInterval[0]);
            newInterval[1] = max(intervals[endIdx][1], newInterval[1]);
        }

        intervals.erase(intervals.begin() + startIdx, intervals.begin() + endIdx + 1);
        intervals.insert(intervals.begin() + startIdx, newInterval);


        return intervals;
    }
};