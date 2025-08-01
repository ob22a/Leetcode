class Solution {
public:
    void dfs(int row,int col,int i,int j,vector<vector<bool>>& seen,vector<vector<char>>& board){
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        
        vector<pair<int,int>> region;
        bool foundEdge=false;
        stack<pair<int,int>> stk;
        region.push_back({i,j});
        stk.push({i,j});

        while(!stk.empty()){
            auto [x,y]=stk.top(); stk.pop();
            for(auto p:dir){
                int nx=x+p[0],ny=y+p[1];
                if(nx>=0 && ny>=0 && nx<row && ny<col){
                    if((nx==0 || ny==0 || nx==row-1 || ny==col-1) && board[nx][ny]=='O'){
                        foundEdge=true;
                    }
                    if(!seen[nx][ny] && board[nx][ny]=='O'){
                        seen[nx][ny]=true;
                        stk.push({nx,ny});
                        region.push_back({nx,ny});
                    }
                }
            }
        }

        if(!foundEdge){
            for(const pair<int,int>& p:region){
                board[p.first][p.second]='X';
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int row=board.size(),col=board[0].size();
        vector<vector<bool>> seen(row,vector<bool>(col,false));

        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(board[i][j]=='O' && !seen[i][j]){
                    seen[i][j]=true;
                    if(i!=0 && i!=row-1 && j!=0 && j!=col-1) dfs(row,col,i,j,seen,board);
                }
            }
        }
    }
};