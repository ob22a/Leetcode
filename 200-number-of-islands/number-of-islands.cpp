class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size(),col=grid[0].size();
        
        stack<pair<int,int>> stk;
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        int number=0;

        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(grid[i][j]=='1'){
                    grid[i][j]='0';
                    ++number;
                    stk.push({i,j});
                    while(!stk.empty()){
                        auto[x,y]=stk.top(); stk.pop();
                        for(auto p:dir){
                            int nx=x+p[0],ny=y+p[1];
                            if(nx>=0 && ny>=0 && nx<row && ny<col && grid[nx][ny]=='1'){
                                grid[nx][ny]='0';
                                stk.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }
        return number;
    }
};