class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int start = 0, end = n-1;
        int maxArea = 0;

        while(start <= end){
            int currHeight = min(height[start], height[end]);
            int currWidth = end - start;

            maxArea = max(maxArea, currHeight * currWidth);

            if(height[start] < height[end])
                start++;
            else
                end--;
        }
        return maxArea;
    }
};