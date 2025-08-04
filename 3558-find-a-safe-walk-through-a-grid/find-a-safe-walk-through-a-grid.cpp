class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int row=grid.size(),col=grid[0].size();
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<vector<bool>>> seen(row,vector<vector<bool>>(col,vector<bool>(health+1,false)));

        queue<tuple<int,int,int>> q; // i j health
        int curHealth=health-grid[0][0];
        q.push({0,0,curHealth});
        seen[0][0][curHealth]=true;

        while(!q.empty()){
            auto[x,y,h]=q.front(); q.pop();
            if(x==row-1 && y==col-1) return true;
            for(const auto& cor:dir){
                int nx=x+cor[0],ny=y+cor[1];
                if(nx>=0 && ny>=0 && nx<row && ny<col){
                    int newHealth=h-grid[nx][ny];
                    if(newHealth>0 && !seen[nx][ny][newHealth]){
                        q.push({nx,ny,newHealth});
                        seen[nx][ny][newHealth]=true;
                    }
                }
            }
        }
        return false;
    }
};