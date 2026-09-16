class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minCapacity = *max_element(weights.begin(), weights.end());
        int maxCapacity = accumulate(weights.begin(), weights.end(), 0);

        while(minCapacity < maxCapacity){
            int idealCapacity = minCapacity + (maxCapacity-minCapacity)/2;

            int daysTaken = 1,  currWeight = 0;

            for(int weight: weights){
                if(currWeight + weight > idealCapacity){
                    daysTaken++;
                    currWeight = 0;
                }
                currWeight += weight;
            }

            if(daysTaken <= days){
                maxCapacity = idealCapacity;
            }else{
                minCapacity = idealCapacity+1;
            }
        }
        return maxCapacity;
    }
};