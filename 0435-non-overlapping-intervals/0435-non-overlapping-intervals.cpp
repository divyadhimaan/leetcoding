class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int idx = 0, overlappingIntervals = 0;
        sort(intervals.begin(), intervals.end());

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] < intervals[idx][1]){
                overlappingIntervals++;

                //throw away the interval that ends later
                if(intervals[i][1] < intervals[idx][1])
                    idx = i;
            }else{
                idx = i;
            }
        }
        return overlappingIntervals;
    }
};