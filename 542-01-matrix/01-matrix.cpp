class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row=mat.size(),col=mat[0].size();
        vector<vector<int>> sol(row,vector<int>(col,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(mat[i][j]==0){
                    sol[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int directions[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty()){
            auto [x,y]=q.front(); q.pop();
            for(auto& p:directions){
                int nx=x+p[0],ny=y+p[1];
                if(nx>=0 && nx<row && ny>=0 && ny<col && sol[nx][ny]==-1){
                    sol[nx][ny]=sol[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        return sol;
    }
};