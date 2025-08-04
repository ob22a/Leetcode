class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

        vector<vector<int>> minRemoval(row,vector<int>(col,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
        minRemoval[0][0]=grid[0][0];
        pq.push({grid[0][0],0,0});

        while(!pq.empty()){
            auto [r,x,y]=pq.top(); pq.pop();
            if(minRemoval[x][y]<r) continue;
            if(x==row-1 && y==col-1) return r;

            for(const auto& [dx,dy]:dir){
                int nx=x+dx,ny=y+dy;
                if(nx>=0 && ny>=0 && nx<row && ny<col){
                    int newR=r+grid[nx][ny];
                    if(newR<minRemoval[nx][ny]){
                        pq.push({newR,nx,ny});
                        minRemoval[nx][ny]=newR;
                    }
                }
            }
        }
        return -1;
    }
};
