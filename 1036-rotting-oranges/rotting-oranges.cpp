class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int row=grid.size(),col=grid[0].size();
      queue<pair<int,int>> q;
      int freshOranges=0;
      for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            if(grid[i][j]==2){
                q.push({i,j});
            }
            else if(grid[i][j]==1) freshOranges++;
        }
      }

      int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
      int time=0;
      while(!q.empty() && freshOranges!=0){
        int n=q.size();
        bool rotted=false;
        for(int i=0;i<n;++i){
            auto [x,y]=q.front(); q.pop();
            for(auto p:dir){
                int nx=x+p[0],ny=y+p[1];
                if(nx>=0 && ny>=0 && nx<row && ny<col && grid[nx][ny]==1){
                        --freshOranges;
                        rotted=true;
                        q.push({nx,ny});
                        grid[nx][ny]=2;
                }
            }
        }
        
        if(rotted) ++time;
      }

        return (freshOranges==0)?time:-1;
    }
};