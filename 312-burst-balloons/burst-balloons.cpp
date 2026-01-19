class Solution {
public:
    int f(vector<int>& nums, int i, int j){
        if(j<i) return 0;

        int maxi = INT_MIN;
        for(int k=i;k<=j;++k){
            int cost = nums[i-1]*nums[k]*nums[j+1] + f(nums,i,k-1) + f(nums,k+1,j);
            maxi = max(cost,maxi);
        }

        return maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);

        int n = nums.size();

        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-2;i>=1;--i){
            for(int j=i;j<n-1;++j){
                int maxi = 0;
                int partial = nums[i-1]*nums[j+1];
                for(int k=i;k<=j;++k){
                    int cost = partial*nums[k] + dp[i][k-1] + dp[k+1][j];
                    maxi = max(cost,maxi);
                }
                dp[i][j]=maxi;
            }
        }

        return dp[1][n-2];
    }
};