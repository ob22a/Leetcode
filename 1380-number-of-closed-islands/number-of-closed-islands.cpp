class Solution {
public:
    void dfs(vector<vector<int>>& grid,const int& i, const int& j){
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        stack<pair<int,int>> stk;
        stk.push({i,j});
        grid[i][j]=1;

        while(!stk.empty()){
            auto[x,y]=stk.top(); stk.pop();
            for(const auto& cor:dir){
                int nx=x+cor[0],ny=y+cor[1];
                if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny]==0){
                    grid[nx][ny]=1;
                    stk.push({nx,ny});
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();

        for(int i=0;i<row;++i){
            if(grid[i][0]==0) dfs(grid,i,0);
            if(grid[i][col-1]==0) dfs(grid,i,col-1);
        }

        for(int j=0;j<col;++j){
            if(grid[0][j]==0) dfs(grid,0,j);
            if(grid[row-1][j]==0) dfs(grid,row-1,j);
        }

        int count=0;
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(grid[i][j]==0){
                    ++count;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};