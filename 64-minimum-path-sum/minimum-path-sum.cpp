class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        /*
            1. Create a recursive function where f(i,j) would return the minimum sum path to reach i,j from 0,0
            2. start from i,j and move either up or left till you reach 0,0 or pass boundary 
            3. Tabulate the result to avoid recursive space and store computed values
            4. dp[i][j]=min(dp[i-1][j],dp[i][j-1]) and dp[0][0]=arr[0][0]
            5. Since we only need the last row of dp we can space optimize it as well
        */

        int m=grid.size(),n=grid[0].size();
        vector<int> dp(n,INT_MAX);

        for(int i=0;i<m;++i){
            vector<int> temp(n,0);
            for(int j=0;j<n;++j){
                if(i==0 && j==0) temp[0]=grid[0][0];
                else{
                    int left = (j==0)?INT_MAX:temp[j-1];
                    int top = dp[j];
                    temp[j]=min(left,top)+grid[i][j];
                }
            }
            dp=temp;
        }
        return dp[n-1];
    }
};