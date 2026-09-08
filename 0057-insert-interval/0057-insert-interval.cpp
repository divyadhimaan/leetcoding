class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> mergedIntervals;

        int idx = 0;
        while(idx < n && intervals[idx][1] < newInterval[0]){
            mergedIntervals.push_back(intervals[idx]);
            idx++;
        }

        while(idx<n && intervals[idx][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[idx][0]);
            newInterval[1] = max(newInterval[1], intervals[idx][1]);
            idx++;
        }
        mergedIntervals.push_back(newInterval);

        while(idx < n){
            mergedIntervals.push_back(intervals[idx]);
            idx++;
        }
        return mergedIntervals;
    }
};