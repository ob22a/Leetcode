class Solution {
public:
    int rec(vector<vector<int>>& triangle,int i,int j){
        if(i==0 && j==0) return triangle[i][j];
        if(i<0 || j<0 || j>i) return 10001;

        int up = triangle[i][j]+rec(triangle,i-1,j);
        int diag = triangle[i][j]+rec(triangle,i-1,j-1);

        return min(up,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        /*
            1. First create function f(i,j) that indicates the minimum cost to reach that point
            2. Choose the minimum of the row to get the answer
        */
        int n=triangle.size();

        vector<vector<int>> dp;
        for(int i=0;i<n;++i){
            dp.push_back(vector<int>(i+1));
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<=i;++j){
                if(i==0 && j==0) dp[i][j]=triangle[0][0];
                else{
                    int up =(j<=i-1)?dp[i-1][j]:INT_MAX;
                    int diag = (j>0)?dp[i-1][j-1]:INT_MAX;
                    dp[i][j]=min(up,diag)+triangle[i][j];
                }
            }
        }
        
        int sol=INT_MAX;
        for(int i=0;i<n;++i) sol=min(sol,dp[n-1][i]);

        return sol;
    }
};