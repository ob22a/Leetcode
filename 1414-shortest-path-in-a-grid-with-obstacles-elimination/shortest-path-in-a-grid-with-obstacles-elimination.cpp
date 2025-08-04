class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int row=grid.size(),col=grid[0].size();
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<vector<bool>>> seen(row,vector<vector<bool>>(col,vector<bool>(k+1,false)));

        queue<tuple<int,int,int,int>> q; // i j k len
        q.push({0,0,k,0});
        seen[0][0][k]=true;

        while(!q.empty()){
            auto[x,y,z,len]=q.front(); q.pop();
            if(x==row-1 && y==col-1) return len;
            for(const auto& cor:dir){
                int nx=x+cor[0],ny=y+cor[1];
                if(nx>=0 && ny>=0 && nx<row && ny<col){
                    int newZ=z-grid[nx][ny];
                    if(newZ>=0 && !seen[nx][ny][newZ]){
                        seen[nx][ny][newZ]=true;
                        q.push({nx,ny,newZ,len+1});
                    }
                }
            }
        }
        return -1;
    }
};