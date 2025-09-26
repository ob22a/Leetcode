class Solution {
public:
    int f(string word1, string word2, int idx1,int idx2){
        if(idx1<0) return idx2+1;
        if(idx2<0) return idx1+1;

        if(word1[idx1] == word2[idx2]) return f(word1,word2,idx1-1,idx2-1);
        
        return 1 + min (f(word1,word2,idx1,idx2-1),f(word1,word2,idx1-1,idx2));
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size() + 1, n2 = word2.size() + 1;
        vector<vector<int>> dp(n1,vector<int>(n2,0));
        for(int i=0;i<n1;++i) dp[i][0] = i;
        for(int i=0;i<n2;++i) dp[0][i] = i;

        for(int idx1=1;idx1<n1;idx1++){
            for(int idx2=1;idx2<n2;++idx2){
                dp[idx1][idx2] = (word1[idx1-1]==word2[idx2-1]) ? 
                                dp[idx1-1][idx2-1] :
                                1 + min(dp[idx1-1][idx2],dp[idx1][idx2-1]);
            }
        }

        return dp[n1-1][n2-1];
    }
};