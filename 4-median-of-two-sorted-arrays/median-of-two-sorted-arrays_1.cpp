class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sorted;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                sorted.push_back(nums1[i]);
                ++i;
            }
            else{
                sorted.push_back(nums2[j]);
                ++j;
            }
        }
        while(i<nums1.size()) sorted.push_back(nums1[i++]);
        while(j<nums2.size()) sorted.push_back(nums2[j++]);

        int n=sorted.size();
        if(n%2==0){
            int a=sorted[n/2 - 1],b=sorted[n/2];
            return (a+b)/2.0;
        }
        return sorted[n/2]/1.0;
    }
};
