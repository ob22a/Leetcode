class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int left=k,right=k;
        int minimum=nums[k];
        int sol=minimum;
        while(left>0 || right<nums.size()-1){
            if(left==0) ++right;
            else if(right==nums.size()-1) --left;
            else{
                if(nums[left-1]>nums[right+1]) --left;
                else ++right;
            }
            minimum=min(minimum,min(nums[left],nums[right]));
            sol=max(sol,minimum*(right-left+1));
        }
        return sol;
    }
};