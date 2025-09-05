class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        vector<vector<bool>> seen(row,vector<bool>(col,false));
        int nonEmpty=0;
        int start_i=0,start_j=0;
        int end_i=0,end_j=0;
        
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(grid[i][j]!=-1) ++nonEmpty;
                if(grid[i][j]==1){
                    start_i=i; start_j=j;
                }
                else if(grid[i][j]==2){
                    end_i=i; end_j=j;
                }
            }
        }

        int sol=0;
        auto bkt = [&](auto&& self,int i,int j, int cnt)->void{
            if(i<0 || j<0 || i>=row || j>=col || seen[i][j] || grid[i][j]==-1) return;

            if(i==end_i && j==end_j){
                if(cnt==nonEmpty) sol++;
                return;
            }

            seen[i][j]=true;

            self(self,i,j+1,cnt+1); 
            self(self,i+1,j,cnt+1); 
            self(self,i,j-1,cnt+1);
            self(self,i-1,j,cnt+1);

            seen[i][j]=false;
        };

        bkt(bkt,start_i,start_j,1);
        return sol;
    }
};