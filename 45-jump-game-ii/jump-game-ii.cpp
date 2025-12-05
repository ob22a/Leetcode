class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,0);
        for(int idx=n-2;idx>=0;--idx){
            int sol = 1e9;
            for(int i=1;i<=nums[idx];++i){
                if(i+idx>=n) break;
                sol = min(sol,dp[idx+i] + 1);
            }
            dp[idx]=sol;
        }

        return dp[0];
    }
};