class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> seenCol(n),diag1(2*n),diag2(2*n);
        auto isValid = [&](int row,int col)->bool{
            if(seenCol[col]) return false;
            if(diag1[row+col]) return false;
            if(diag2[row-col+n-1]) return false;
            return true;
        };

        int count=0;
        auto backtrack = [&](auto&& self,int row){
            if(row==n){
                ++count;
                return;
            }
            for(int col=0;col<n;++col){
                if(isValid(row,col)){
                    seenCol[col]=true;
                    diag1[row+col]=true;
                    diag2[row-col+n-1]=true;

                    self(self,row+1);

                    seenCol[col]=false;
                    diag1[row+col]=false;
                    diag2[row-col+n-1]=false;
                }
            }
        };

        backtrack(backtrack,0);

        return count;
    }
};