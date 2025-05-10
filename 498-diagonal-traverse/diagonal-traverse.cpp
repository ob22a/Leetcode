class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result;
        int row=mat.size(),col=mat[0].size();
        for(int d=0;d<row+col-1;++d){
            int r,c;
            if(d%2==0){ //Going up
                r=min(d,row-1);
                c=d-r;
                while(r>=0 && c<col){
                    result.push_back(mat[r][c]);
                    --r; ++c;
                }
            }
            else{ //going down
                c=min(d,col-1);
                r=d-c;
                while(c>=0 && r<row){
                    result.push_back(mat[r][c]);
                    ++r; --c;
                }
            }
        }
        return result;
    }
};