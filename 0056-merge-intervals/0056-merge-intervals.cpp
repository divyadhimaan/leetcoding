class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        sort(intervals.begin(), intervals.end());

        mergedIntervals.push_back(intervals[0]);
        int idx = 0;

        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0] <= mergedIntervals[idx][1]){
                mergedIntervals[idx][1] = max(mergedIntervals[idx][1], intervals[i][1]);
            }else{
                mergedIntervals.push_back(intervals[i]);
                idx++;
            }
        }
        return mergedIntervals;
    }
};