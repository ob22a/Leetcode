class Solution {
public:
    int f(string& text1, string& text2, int idx1, int idx2){
        if(idx1<0 || idx2<0) return 0;

        if(text1[idx1]==text2[idx2]) return 1 + f(text1,text2,idx1-1,idx2-1);
        return max(f(text1,text2,idx1-1,idx2),f(text1,text2,idx1,idx2-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size()+1, n2 = text2.size()+1;
        vector<int> dp(n2,0); // allowing for -1 idx as 0
        vector<int> temp(n2,0);

        for(int idx1=1;idx1<n1;++idx1){
            for(int idx2=1;idx2<n2;++idx2){
                dp[idx2] = (text1[idx1-1]==text2[idx2-1]) ? 
                                1 + temp[idx2-1] : 
                                max(temp[idx2],dp[idx2-1]);
            }
            temp = dp;
        }
        return dp[n2-1];
    }
};