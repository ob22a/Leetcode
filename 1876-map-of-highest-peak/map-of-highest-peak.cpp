class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row=isWater.size(),col=isWater[0].size();
        vector<vector<int>> sol(row,vector<int>(col,-1));
        queue<pair<int,int>> q;

        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(isWater[i][j]==1){
                    sol[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int directions[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            auto [x,y]=q.front(); q.pop();
            for(auto p:directions){
                int nx=x+p[0],ny=y+p[1];
                if(nx>=0 && ny>=0 && nx<row && ny<col && sol[nx][ny]==-1){
                    sol[nx][ny]=sol[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        return sol;
    }
};