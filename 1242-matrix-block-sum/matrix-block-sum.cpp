class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        // First generate prefix sum
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> preSum(m+1,vector<int>(n+1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;++j){
                preSum[i+1][j+1]=preSum[i+1][j]+preSum[i][j+1]-preSum[i][j]+mat[i][j];
            }
        }
        vector<vector<int>> sol(m,vector<int>(n));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                // DEFINE THE BORDERS
                int i1=max(0,i-k), i2=min(m-1,i+k);
                int j1=max(0,j-k), j2=min(n-1,j+k);

                sol[i][j]=preSum[i2+1][j2+1]-preSum[i1][j2+1]-preSum[i2+1][j1]+preSum[i1][j1];
            }
        }
        return sol;
    }
};