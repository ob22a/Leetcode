class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int swap=0;
        for(int i=0;i<n-1;++i){
            if(nums[i]>nums[i+1]) ++swap;
            if(swap>1) return false;
        }
        return (swap==0 || nums[n-1]<=nums[0]);
    }
};