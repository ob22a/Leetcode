class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size() + 1, n2 = str2.size() + 1;
        vector<vector<int>> dp(n1, vector<int>(n2, 0));

        for(int idx1=1;idx1<n1;++idx1){
            for(int idx2=1;idx2<n2;++idx2){
                dp[idx1][idx2] = (str1[idx1-1]==str2[idx2-1]) ? 
                                1 + dp[idx1-1][idx2-1] :
                                max(dp[idx1-1][idx2],dp[idx1][idx2-1]);
            }
        }

        string sol;
        int i = n1-1, j = n2-1;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                sol+=str1[i-1];
                --i; --j;
            }
            else if(dp[i][j-1]>dp[i-1][j]){
                sol += str2[j-1]; --j;
            } else{
                sol += str1[i-1]; --i;
            }
        }

        while (i > 0) {
            sol += str1[i-1];
            --i;
        }
        while (j > 0) {
            sol += str2[j-1];
            --j;
        }

        reverse(sol.begin(),sol.end());

        return sol;
    }
};