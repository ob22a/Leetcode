class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int N = 1 << n;
        vector<int> dp(N, 0);

        vector<vector<int>> gcds(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                gcds[i][j] = __gcd(nums[i], nums[j]);

        for(int mask = 0; mask < N; mask++){
            int count = __builtin_popcount(mask);
            int op = count / 2 + 1;

            for(int i = 0; i < n; i++){
                if((mask >> i) & 1) continue;
                for(int j = i+1; j < n; j++){
                    if((mask >> j) & 1) continue;
                    int new_mask = mask | (1 << i) | (1 << j);
                    dp[new_mask] = max(dp[new_mask], dp[mask] + op * gcds[i][j]);
                }
            }
        }

        return dp[N-1];
    }
};
