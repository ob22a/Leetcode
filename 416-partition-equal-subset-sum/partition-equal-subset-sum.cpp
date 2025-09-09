class Solution {
public:
    int rec(int i,int sum,int total,vector<int>& nums){
        if(i>=nums.size() || sum>total/2) return false;
        if(sum==total/2) return true;
        return rec(i+1,sum+nums[i],total,nums) || rec(i+1,sum,total,nums);
    }
    bool canPartition(vector<int>& nums) {
        int total=0,n=nums.size();
        for(int num:nums) total+=num;
        if(total%2!=0) return false;
        int target = total/2;
        
        vector<vector<bool>> dp(n+1,vector<bool>(target+1,false)); // Store index and sum
        for(int i=0;i<n;++i) dp[i][target]=true;

        for(int i=n-1;i>=0;--i){
            for(int sum=target-1;sum>=0;--sum){
                bool take = (sum+nums[i]>target)?false:dp[i+1][sum+nums[i]];
                bool notTake = dp[i+1][sum];
                dp[i][sum]=take || notTake;
            }
        }

        return dp[0][0];
    }
};