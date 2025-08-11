class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> seenCol(n),diag1(2*n),diag2(2*n);
        /* These two diagonals can be seen as linear functions
            y=x+b and y=-x+b 
        The sum of x and y will give b for one set of diagonals
        The differnce of y and x(x and y as well) will give b for the other diagonal

        Let diag1 be x+y and diag2 be x-y
            */
        
        auto isValid=[&](int row,int col)->bool{
            if(seenCol[col]) return false;
            if(diag1[row+col]) return false;
            if(diag2[row-col+n+1]) return false;

            return true;
        };

        vector<int> rowCol(n,-1);
        vector<vector<int>> sol;
        auto backtrack = [&](auto&& self,int row){
            if(row==n){
                sol.push_back(rowCol);
                return;
            }
            for(int col=0;col<n;++col){
                if(isValid(row,col)){
                    rowCol[row]=col;
                    seenCol[col]=true;
                    diag1[row+col]=true;
                    diag2[row-col+n+1]=true;

                    self(self,row+1);

                    rowCol[row]=-1;
                    seenCol[col]=false;
                    diag1[row+col]=false;
                    diag2[row-col+n+1]=false;
                }
            }
        };

        backtrack(backtrack,0);
        vector<vector<string>> board(sol.size(),vector<string>(n,string(n,'.')));
        for(int i=0;i<sol.size();++i){
            for(int j=0;j<n;++j){
                int k=sol[i][j];
                board[i][j][k]='Q';
            }
        }

        return board;
    }
};