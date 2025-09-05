class Solution {
public:
    int uniquePaths(int m, int n) {
        /*
            1. Create a function f(i,j) that returns the number of unique ways to reach from 0,0 to i,j
            2. This function can be solved recursively by attempting to move up or left from i,j and returning 1 when we reach 0,0 we return 1
            3. This will have a lot of overlapping sub problems since f(i,j) is it self a solution if the array size was i+1 * j+1
            4. We can apply memoization but to save the recursive stack space it is better to use tabulation 
            5. We access dp[i-1][j] and dp[i][j-1] so we don't need the whole n*m dp we only need the last row 
            6. This will reduce the space complexity from m*n to n
        */

        vector<int> dp(n,0);

        for(int i=0;i<m;++i){
            vector<int> temp(n,0);
            for(int j=0;j<n;++j){
                if(i==0 && j==0) temp[j]=1;
                else{
                    temp[j]=dp[j];
                    if(j>0) temp[j]+=temp[j-1];
                }
            }
            dp=temp;
        }

        return dp[n-1];
    }
};