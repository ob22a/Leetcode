class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        int sol=1;
        for(int i=0;i<n;++i){
            int count=1;
            for(int j=i+1;j<n;++j){
                if(nums[j]>nums[j-1]) ++count;
                else break;
            }
            sol=max(sol,count);
        }
        return sol;
    }
};