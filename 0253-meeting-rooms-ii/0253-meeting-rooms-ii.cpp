class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int,char>> events;
        for(int i=0;i<intervals.size();i++){
            events.push_back({intervals[i][0], 's'});
            events.push_back({intervals[i][1], 'e'});
        }

        sort(events.begin(), events.end());

        int roomsNeeded = 0, maxRooms = INT_MIN;
        for(int i=0;i<events.size();i++){
            if(events[i].second == 's')
                roomsNeeded++;
            else
                roomsNeeded--;

            maxRooms = max(maxRooms, roomsNeeded);
        }
        return maxRooms;
    }
};