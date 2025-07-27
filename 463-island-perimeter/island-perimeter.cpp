class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int sol=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]){
                    if(i==0 || !grid[i-1][j]) sol++;
                    if(i==n-1 || !grid[i+1][j]) sol++;
                    if(j==0 || !grid[i][j-1]) sol++;
                    if(j==m-1 || !grid[i][j+1]) sol++;
                }
            }
        }
        return sol;
    }
};