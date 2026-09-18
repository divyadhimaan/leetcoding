class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i=0,j=0;

        int ele1 = 0, ele2=0;
        for(int cnt =0; cnt <= (n+m)/2 ;cnt++){
            ele2 = ele1;
            if(i != n && j != m)
            {
                if(nums1[i] < nums2[j])
                    ele1 = nums1[i++];
                else
                    ele1 = nums2[j++];
            }else if(i<n){
                ele1 = nums1[i++];
            }else{
                ele1 = nums2[j++];
            }
        }

        if((n+m) % 2==1)
            return (double) ele1;
        return (double)((double)ele1+ele2)/2.0;
    }
};