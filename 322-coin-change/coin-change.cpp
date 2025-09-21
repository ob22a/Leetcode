class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,INT_MAX)); //idx * sum+1
        for(int i=0;i<n;++i) dp[i][0]=0;
        for(int j=0;j<=amount;++j){
            if(j%coins[0]==0) dp[0][j]=j/coins[0];
        }

        for(int idx=1;idx<n;++idx){
            for(int sum=1;sum<=amount;++sum){
                long long notTake = dp[idx-1][sum];
                long long take = INT_MAX;

                if(sum>=coins[idx]) take = 1ll + dp[idx][sum-coins[idx]];
                dp[idx][sum]=min(take,notTake);
            }
        }
        
        int sol = dp[n-1][amount];
        if(sol==INT_MAX) sol=-1;

        return sol;
    }
};