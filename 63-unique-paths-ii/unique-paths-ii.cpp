class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Basically similar to unique sum one but we need to set the number of ways to reach the obstacle to zero 

        int row=obstacleGrid.size(),col=obstacleGrid[0].size();

        // Obstacle could be at the start or the end
        if(obstacleGrid[0][0] || obstacleGrid[row-1][col-1]) return 0;
        vector<int> dp(col,0);

        for(int i=0;i<row;i++){
            vector<int> temp(col,0);
            for(int j=0;j<col;++j){
                if(i==0 && j==0) temp[j]=1;
                else if(!obstacleGrid[i][j]){
                    temp[j]=dp[j];
                    if(j>0) temp[j]+=temp[j-1];
                }
            }
            dp=temp;
        }
        return dp[col-1];
    }
};