class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        vector<long long> rowSum(row,0),colSum(col,0);
        long long totalSum=0;
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                totalSum+=grid[i][j];
                rowSum[i]+=grid[i][j];
                colSum[j]+=grid[i][j];
            }
        }
        long long sum=0;
        for(int i=0;i<row;++i){
            sum+=1LL*rowSum[i];
            if(sum==totalSum-sum) return true;
        }
        sum=0;
        for(int j=0;j<col;++j){
            sum+=1LL*colSum[j];
            if(sum==totalSum-sum) return true;
        }

        return false;
    }
};