class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

        vector<vector<int>> minRemoval(row,vector<int>(col,INT_MAX));
        deque<tuple<int,int,int>> dq;
        minRemoval[0][0]=grid[0][0];
        dq.push_front({grid[0][0],0,0});

        while(!dq.empty()){
            auto [r,x,y]=dq.front(); dq.pop_front();
            if(minRemoval[x][y]<r) continue;
            if(x==row-1 && y==col-1) return r;

            for(const auto& [dx,dy]:dir){
                int nx=x+dx,ny=y+dy;
                if(nx>=0 && ny>=0 && nx<row && ny<col){
                    int cost=grid[nx][ny];
                    int newR=r+cost;
                    if(newR<minRemoval[nx][ny]){
                        if(cost==0){
                            dq.push_front({newR,nx,ny});
                        }
                        else{
                            dq.push_back({newR,nx,ny});
                        }
                        minRemoval[nx][ny]=newR;
                    }
                }
            }
        }
        return -1;
    }
};