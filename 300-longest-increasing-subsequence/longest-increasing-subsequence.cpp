class Solution {
public:
    int f(vector<int>& nums, int prevIdx, int idx){
        if(idx==nums.size()) return 0;
        int notPick = f(nums,prevIdx,idx+1);
        int pick = 0;
        
        if(prevIdx==-1 || nums[idx]>nums[prevIdx]) pick = 1 + f(nums,idx,idx+1);

        return max(pick,notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        // Find some function f(i) where this would return the longest subsequnce
        int n = nums.size();

        vector<int> dp(n+1,0);
        vector<int> temp(n+1,0);

        for(int idx=n-1;idx>=0;--idx){
            for(int prevIdx=idx-1;prevIdx>=-1;--prevIdx){
                int notPick = temp[prevIdx+1];
                int pick = 0;
                if(prevIdx==-1 || nums[idx]>nums[prevIdx]) pick = 1 + temp[idx+1];

                dp[prevIdx+1] = max(pick,notPick);
            }
            temp = dp;
        }
        return dp[0];
    }
};