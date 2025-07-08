class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int sol=0;
        int l=0,mask=0;
        for(int r=0;r<nums.size();++r){
            while((mask & nums[r])!=0) mask^=nums[l++];
            mask|=nums[r];
            sol=max(sol,r-l+1);
        }
        return sol;
    }
};