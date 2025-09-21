class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        typedef unsigned long long ull;
        vector<ull> dp(amount+1,0); // sum+1

        dp[0]=1;
        for(int j=0;j<=amount;++j){
            if(j%coins[0]==0) dp[j]=1;
        }

        for(int i=1;i<n;++i){
            for(int sum=1;sum<=amount;++sum){
                ull notTake = dp[sum];
                ull take = 0;
                if(sum>=coins[i]) take=dp[sum-coins[i]];

                dp[sum]=take+notTake;
            }
        }

        return dp[amount];
    }
};