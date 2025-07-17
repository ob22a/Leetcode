class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int l=1,r=nums.size()-2;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m-1]<nums[m] && nums[m]>nums[m+1]) return m;
            else if(nums[m+1]>nums[m]) l=m+1;
            else r=m-1;
        }
        if(nums[0]>nums[1]) return 0;
        return n-1;
    }
};