class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        while(low < high){
            int mid = low + (high-low)/2;

            int hoursSpent = 0;

            for(int pile: piles){
                hoursSpent += (pile/mid) + (pile%mid!=0);
            }

            if(hoursSpent <=h){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return high;
    }
};