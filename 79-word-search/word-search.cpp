class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size(),col=board[0].size();
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

        auto dfs = [&](auto&& dfs,int i,int j,int idx)->bool{
            if(idx==word.size()) return true;
            if(i<0 || j<0 || i>=row || j>=col || board[i][j]!=word[idx]) return false;

            char temp=board[i][j];
            board[i][j]='.';

            bool found = dfs(dfs,i+1,j,idx+1) ||
                        dfs(dfs,i,j+1,idx+1) ||
                        dfs(dfs,i-1,j,idx+1) ||
                        dfs(dfs,i,j-1,idx+1);
            board[i][j]=temp;
            
            return found;
        };

        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(dfs(dfs,i,j,0)) return true;
            }
        }
        return false;
    }
};