class Solution {
public:
    int f(vector<int>& nums, int target, int idx, int sum){
        if(idx<0) return sum==target;

        int pos = f(nums,target,idx-1,sum+nums[idx]);
        int neg = f(nums,target,idx-1,sum-nums[idx]);

        return pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total = accumulate(nums.begin(),nums.end(),0ll);
        if (abs(target) > total) return 0; 

        vector<vector<int>> dp(n+1,vector<int>(2*total +1,0));

        dp[0][total]=1; // base case

        for(int idx=0;idx<n;++idx){
            for(int s=-total;s<=total;++s){
                if(dp[idx][s+total]==0) continue;
                dp[idx+1][s + nums[idx] + total] += dp[idx][s+total];
                dp[idx+1][s - nums[idx] + total] += dp[idx][s+total];
            }
        }

        return dp[n][target+total];
    }
};