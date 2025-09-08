class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        /*
            1. In all steps the robots move down so this is a 3D problem not 4D i j1 j2 
            2. f(i,j1,j2) should return the maximum collected till the bottom
            3. At each step there is a nine combination movement and the maximum of that is selected
            4. Edge case if the robot pass the border return very small number so that the rest won't be affected 
            5. Base case when i==n-1 since we are moving downwards in the recursion
        */

        vector<vector<vector<int>>> dp;
        int row=grid.size();
        int col=grid[0].size();
        dp.assign(row, vector<vector<int>>(col, vector<int>(col, INT_MIN)));

        for(int j1=0;j1<col;++j1){
            for(int j2=0;j2<col;++j2){
                if(j1==j2) dp[row-1][j1][j2]=grid[row-1][j1];
                else dp[row-1][j1][j2]=grid[row-1][j1]+grid[row-1][j2];
            }
        }

        for(int i=row-2;i>=0;--i){
            for(int j1=0;j1<col;++j1){
                for(int j2=0;j2<col;++j2){
                    int best=INT_MIN;
                    for(int dx=-1;dx<=1;++dx){
                        for(int dy=-1;dy<=1;++dy){
                            int new_j1=j1+dx;
                            int new_j2=j2+dy;

                            if(new_j1<0 || new_j2<0 || new_j1>=col || new_j2>=col) continue;
                            best=max(best,dp[i+1][new_j1][new_j2]);
                        }
                    }
                    int cherries = (j1==j2)?grid[i][j1]:grid[i][j1]+grid[i][j2];
                    dp[i][j1][j2]=best+cherries;
                }
            }
        }

        return dp[0][0][col-1];
    }
};