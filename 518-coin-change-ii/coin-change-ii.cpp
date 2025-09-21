class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        typedef unsigned long long ull;
        vector<ull> dp(amount+1,0); // sum+1

        dp[0]=1;

        for(int coin:coins){
            for(int sum=coin;sum<=amount;++sum){
                dp[sum]+=dp[sum-coin];
            }
        }

        return dp[amount];
    }
};