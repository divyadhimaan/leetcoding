class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int low = 0, high = n-1;

        int maxArea = INT_MIN;
        while(low < high){
            int currWidth = high-low;
            int currHeight = min(height[high], height[low]);

        
            maxArea = max(maxArea, currWidth*currHeight);
            if(height[low] < height[high])
                low++;
            else
                high--;
        }
        return maxArea;
    }
};