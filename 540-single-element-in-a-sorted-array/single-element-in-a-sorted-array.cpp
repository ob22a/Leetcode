class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        /*
        The intuition is that for two similar numbers their index is 
            even,odd if it is left of the soln
            odd,even if it is right of soln
        */
        int n=nums.size();
        if(n==1 || nums[0]!=nums[1]) return nums[0];
        if(nums[n-2]!=nums[n-1]) return nums[n-1];

        int l=1,r=n-2;
        int ans=0;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]!=nums[m-1] && nums[m]!=nums[m+1]) return nums[m];
            else if((m%2==1 && nums[m]==nums[m-1]) || 
                    (m%2==0 && nums[m]==nums[m+1])) l=m+1;
            else r=m-1;
        }
        return nums[l];
    }
};