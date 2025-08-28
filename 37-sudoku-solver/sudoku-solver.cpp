class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();

        // Fill the initial board data in the sets
        vector<vector<bool>> row(n,vector<bool>(n,false));
        vector<vector<bool>> col(n,vector<bool>(n,false));
        vector<vector<bool>> squares(n,vector<bool>(n,false));

        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]!='.'){
                    int idx=board[i][j]-'0';
                    row[i][idx-1]=true;
                    col[j][idx-1]=true;
                    squares[(i/3)*3+j/3][idx-1]=true;
                }
            }
        }

        auto bkt = [&](auto& self,vector<vector<char>>& board)->bool{
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    if(board[i][j]=='.'){
                        for(int num=0;num<=8;++num){
                            int idx=(i/3)*3+j/3;
                            if(!row[i][num] && !col[j][num] && !squares[idx][num]){
                                board[i][j]=num+1+'0';
                                row[i][num]=true;
                                col[j][num]=true;
                                squares[idx][num]=true;
                                if(self(self,board)) return true;
                                else {
                                    board[i][j]='.';
                                    row[i][num]=false;
                                    col[j][num]=false;
                                    squares[idx][num]=false;
                                }
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        };

        bkt(bkt,board);
        return;
    }
};