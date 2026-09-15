class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();

        int low = 1, high = n-2;
        int peak = -1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(arr[mid-1] <= arr[mid])
            {
                peak = mid;
                low = mid+1;
            }else if(arr[mid] < arr[mid-1]){
                high = mid-1;
            }

        }
        return peak;
    }
};