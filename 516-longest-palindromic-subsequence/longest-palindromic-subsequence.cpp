class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // Basically LCS with s and reverse(s)
        int n=s.size() + 1;
        vector<int> dp(n,0);
        vector<int> temp(n,0);

        for(int idx1=1;idx1<n;++idx1){
            for(int idx2=1;idx2<n;++idx2){
                dp[idx2] = (s[idx1-1]==s[n-idx2-1])?
                                1 + temp[idx2-1] :
                                max(temp[idx2],dp[idx2-1]);
            }
            temp = dp;
        }

        // for(vector<int> vec:dp){
        //     for(int x:vec) cout<<x<<" ";
        //     cout<<endl;
        // }
        
        return dp[n-1];
    }
};