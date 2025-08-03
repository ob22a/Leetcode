class Solution {
public:
    int dfs(vector<vector<int>>& grid,const int& i, const int& j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0) return 0;
        
        int sum=1;
        grid[i][j]=0;

        sum+=dfs(grid,i+1,j);
        sum+=dfs(grid,i,j+1);
        sum+=dfs(grid,i-1,j);
        sum+=dfs(grid,i,j-1);

        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        int maxArea=0;

        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(grid[i][j]==1){
                    maxArea=max(maxArea,dfs(grid,i,j));
                }
            }
        }
        return maxArea;
    }
};