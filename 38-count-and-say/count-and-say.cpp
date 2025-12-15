class Solution {
public:
    string RLE(string s){
        int n = s.size();
        string sol="";
        int count = 1;
        char numChar = s[0];

        for(int i=1;i<n;++i){
            if(s[i]!=numChar){
                sol+=count+'0';
                sol+=numChar;
                count=1;
                numChar=s[i];
            }
            else ++count;
        }

        if(count!=0){
            sol+=count+'0';
            sol+=numChar;
        }

        return sol;
    }
    string countAndSay(int n) {
        vector<string> dp(n,"1");

        for(int i=1;i<n;++i){
            dp[i]=RLE(dp[i-1]);
        }

        return dp[n-1];
    }
};