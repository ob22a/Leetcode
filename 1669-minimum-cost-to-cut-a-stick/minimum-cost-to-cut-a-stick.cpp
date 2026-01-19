class Solution {
public:
    int f(vector<int>& cuts, int i, int j){
        if(j==i+1) return 0;
        int totalCost = 1e9;
        for(int k=i+1;k<j;++k){
            int val = f(cuts,i,k)+f(cuts,k,j)+cuts[j]-cuts[i];
            totalCost = min(totalCost, val);
        }

        return totalCost;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(),cuts.end());
        int size = cuts.size();

        // Tabulate the recursive solution 
        vector<vector<long long>> dp(size,vector<long long>(size,0));

        for(int i=size-1;i>=0;--i){
            for(int j=i+2;j<size;++j){ // i+1 is a base case 
                long long totalCost = 1e9;
                for(int k=i+1;k<j;++k){
                    long long val = dp[i][k]+dp[k][j]+cuts[j]-cuts[i];
                    totalCost = min(totalCost, val);
                }
                dp[i][j] = totalCost;
            }
        }

        //int ans = f(cuts,0,size-1);

        return dp[0][size-1];
    }
};