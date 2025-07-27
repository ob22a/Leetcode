class Solution {
public:
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>& seen,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0 || seen[i][j]) return 0;
        seen[i][j]=true;
        int sum=4;

        if (i > 0 && grid[i - 1][j] == 1) sum -= 1;
        if (i < grid.size() - 1 && grid[i + 1][j] == 1) sum -= 1;
        if (j > 0 && grid[i][j - 1] == 1) sum -= 1;
        if (j < grid[0].size() - 1 && grid[i][j + 1] == 1) sum -= 1;

        sum+=dfs(grid,seen,i,j+1);
        sum+=dfs(grid,seen,i+1,j);
        sum+=dfs(grid,seen,i,j-1);
        sum+=dfs(grid,seen,i-1,j);

        return sum;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> seen(n,vector<bool>(m,false));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1){
                    return dfs(grid,seen,i,j);
                }
            }
        }
        return 0;
    }
};