class Solution {
public:
    pair<int,int> dfs(const vector<vector<int>>& land, vector<vector<bool>>& seen, int& i, int& j){
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        int row=land.size(),col=land[0].size();
        stack<pair<int,int>> stk;
        stk.push({i,j});
        int endX=i,endY=j;

        while(!stk.empty()){
            auto [x,y]=stk.top(); stk.pop();
            endX=max(endX,x);
            endY=max(endY,y);
            for(auto& p:dir){
                int nx=x+p[0],ny=y+p[1];
                if(nx>=0 && ny>=0 && nx<row && ny<col && !seen[nx][ny] && land[nx][ny]==1){
                    stk.push({nx,ny});
                    seen[nx][ny]=true;
                }
            }
        }

        return {endX,endY};
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int row=land.size(),col=land[0].size();
        vector<vector<int>> sol;
        vector<vector<bool>> seen(row,vector<bool>(col,false));
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(!seen[i][j] && land[i][j]==1){
                    seen[i][j]=true;
                    pair<int,int> p=dfs(land,seen,i,j);
                    sol.push_back({i,j,p.first,p.second});
                }
            }
        }
        return sol;
    }
};