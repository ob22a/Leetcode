class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int row=grid.size(),col=grid[0].size();
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        
        vector<vector<int>> maxHealth(row,vector<int>(col,0));
        priority_queue<tuple<int,int,int>> pq; // Health i j
        int initHealth=health-grid[0][0];
        if(initHealth<=0) return false;
        maxHealth[0][0]=initHealth;
        pq.push({initHealth,0,0});

        while(!pq.empty()){
            auto [H,x,y]=pq.top(); pq.pop();
            if(H<maxHealth[x][y]) continue;
            if(x==row-1 && y==col-1) return true;
            for(const auto& [dx,dy]:dir){
                int nx=x+dx,ny=y+dy;
                if(nx>=0 && ny>=0 && nx<row && ny<col){
                    int newHealth=H-grid[nx][ny];
                    if(maxHealth[nx][ny]<newHealth){
                        maxHealth[nx][ny]=newHealth;
                        pq.push({newHealth,nx,ny});
                    }
                }
            }
        }
        return false;
    }
};