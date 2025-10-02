class Solution {
public:
    int f(string& s, string& p, int i, int j){
        if(i<0 && j<0) return true;
        if(j<0) return false;
        if(i<0){
            for(int idx=0;idx<=j;++idx){
                if(p[idx]!='*') return false;
            }
        }

        if(p[j] == '*') return f(s,p,i,j-1) || f(s,p,i-1,j);
        if(p[j]=='?' || s[i]==p[j]) return f(s,p,i-1,j-1);

        return false;
    }
    bool isMatch(string s, string p) {
        int n = s.size() + 1;
        int m = p.size() + 1;

        vector<bool> dp(m,false);
        vector<bool> temp(m,false);
        temp[0] = true;
    
        for (int j = 1;j<m; ++j) {
            if (p[j-1] == '*') temp[j] = temp[j-1];
        }

        for(int i=1;i<n;++i){
            for(int j=1;j<m;++j){
                dp[j] =(p[j-1] == '*')? dp[j-1] || temp[j]:
                        (p[j-1]=='?' || s[i-1]==p[j-1])? temp[j-1] : false;
            }
            temp = dp;
        }

        return temp[m-1];
    }
};