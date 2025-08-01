class Solution {
public:
    void dfs(int row,int col,int i,int j,vector<vector<bool>>& seen,const vector<vector<char>>& board){
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        stack<pair<int,int>> stk;
        stk.push({i,j});
        while(!stk.empty()){
            auto [x,y]=stk.top(); stk.pop();
            for(auto& p:dir){
                int nx=x+p[0],ny=y+p[1];
                if(nx>=0 && ny>=0 && nx<row && ny<col && !seen[nx][ny] && board[nx][ny]=='O'){
                    seen[nx][ny]=true;
                    stk.push({nx,ny});
                }
            }
        }
        
    }
    void solve(vector<vector<char>>& board) {
        int row=board.size(),col=board[0].size();
        vector<vector<bool>> seen(row,vector<bool>(col,false));

        for(int i=0;i<row;++i){
            if(board[i][0]=='O') dfs(row,col,i,0,seen,board);
            if(board[i][col-1]=='O') dfs(row,col,i,col-1,seen,board);
        }

        for(int j=0;j<col;++j){
            if(board[0][j]=='O') dfs(row,col,0,j,seen,board);
            if(board[row-1][j]=='O') dfs(row,col,row-1,j,seen,board);
        }

        for(int i=1;i<row-1;i++){
            for(int j=1;j<col-1;++j){
                if(board[i][j]=='O' && !seen[i][j]) board[i][j]='X';
            }
        }
    }
};