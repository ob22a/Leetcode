class Solution {
public:
    int f(string& s,string& t, int i, int j){
        if(j<0) return 1;
        if(i<0) return 0;

        int noMatch = f(s,t,i-1,j);
        int match = (s[i]==t[j])?f(s,t,i-1,j-1):0;

        return match + noMatch;
    }
    int numDistinct(string s, string t) {
        int n1=s.size() + 1,n2=t.size() + 1;
        typedef unsigned long long ull;
        vector<ull> dp(n2,0);
        vector<ull> temp(n2,0);
        temp[0] = 1; dp[0] = 1;

        for(int i=1;i<n1;++i){
            for(int j=1;j<n2;++j){
                ull noMatch = temp[j];
                ull match = (s[i-1]==t[j-1])?temp[j-1]:0;
                dp[j] = + match + noMatch;
            }
            temp = dp;
        }

        return dp[n2-1];
    }
};