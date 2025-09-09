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
        
        vector<bool> dp(target+1,false);
        dp[target]=true;

        for(int i=n-1;i>=0;--i){
            for(int sum=0;sum<target;++sum){
                if(sum+nums[i]<=target) dp[sum] = dp[sum] || dp[nums[i]+sum];
            }
        }

        return dp[0];
    }
};