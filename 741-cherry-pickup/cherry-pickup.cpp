class Solution {
public:
    // int rec(vector<vector<int>>& grid,int n,int i1,int j1,int i2){
    //     int j2=i1+j1-i2;
    //     if(i1>=n || i2>=n || j1>=n || j2>=n ||
    //         i1<0 || i2<0 || j1<0 || j2<0 ||
    //         grid[i1][j1]==-1 || grid[i2][j2]==-1) return INT_MIN;

    //     if(i1==n-1 && j1==n-1) return grid[i1][j1]; // since their sum is equal 

    //     int cherries = grid[i1][j1];
    //     if(i1!=i2 || j1!=j2) cherries+=grid[i2][j2];

    //     int best = max({
    //         rec(grid,n,i1+1,j1,i2),
    //         rec(grid,n,i1+1,j1,i2+1),
    //         rec(grid,n,i1,j1+1,i2),
    //         rec(grid,n,i1,j1+1,i2+1)
    //     });

    //     return cherries+best;
    // }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,INT_MIN)));
        dp[n-1][n-1][n-1]=grid[n-1][n-1];

        for(int i1=n-1;i1>=0;--i1){
            for(int j1=n-1;j1>=0;--j1){
                for(int i2=n-1;i2>=0;--i2){
                    int j2 = i1+j1-i2;
                    if(j2<0 || j2>=n || grid[i1][j1]==-1 || grid[i2][j2]==-1){
                        dp[i1][j1][i2]=INT_MIN;
                        continue;
                    }
                    if(i1==n-1 && j1==n-1) continue;
                    
                    int cherries = grid[i1][j1];
                    if(i1!=i2 || j1!=j2) cherries+=grid[i2][j2];

                    int best = INT_MIN;
                    for(int di1=0;di1<=1;++di1){
                        for(int di2=0; di2<=1;++di2){
                            int ni1 =i1+di1;
                            int nj1 = j1+(di1==0 ? 1 : 0);
                            int ni2 = i2+di2;
                            int nj2 = j2+(di2==0 ? 1 : 0);

                            if (ni1 < n && nj1 < n && ni2 < n && nj2 < n) {
                                best = max(best, dp[ni1][nj1][ni2]);
                            }
                        }
                    }
                    dp[i1][j1][i2]=best+cherries;
                }   
            }
        }
        return max(0,dp[0][0][0]);
    }
};