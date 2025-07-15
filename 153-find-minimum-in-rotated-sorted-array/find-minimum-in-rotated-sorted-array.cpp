class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        int sol=INT_MAX;
        while(l<=r){
            int m=l+(r-l)/2;            
            if(nums[l]<=nums[m]){
                sol=min(sol,nums[l]);
                l=m+1;
            }
            else{
                sol=min(sol,nums[m]);
                r=m-1;
            }
        }
        return sol;
    }
};