class Solution {
public:
    int f(string& s, string& p, int i, int j){
        if(i<0 && j<0) return true;
        if(j<0) return false;
        if(i<0){
            if(p[j]=='*') return f(s,p,i,j-2);
            return false;
        }

        if(p[j]=='.' || (p[j]!='*' && p[j]==s[i])) return f(s,p,i-1,j-1);
        if(p[j]=='*'){
            bool noTake = f(s,p,i,j-2);
            bool take = false;
            if(p[j-1]=='.' || s[i]==p[j-1]) take = f(s,p,i-1,j);

            return take || noTake;
        } 

        return false;
    }
    bool isMatch(string s, string p) {
        int n1=s.size() + 1, n2=p.size() + 1;
        vector<bool> prev(n2,false);
        vector<bool> cur(n2,false);

        prev[0] = true;
        for(int j=2;j<n2;j+=2){
            if(p[j-1]=='*') prev[j] = prev[j-2];
        }

        for(int i=1;i<n1;++i){
            for(int j=1;j<n2;++j){
                bool sol = false;
                if(p[j-1]=='.' || (p[j-1]!='*' && p[j-1]==s[i-1])) sol = prev[j-1];
                if(p[j-1]=='*'){
                    bool noTake = cur[j-2];
                    bool take = false;
                    if(p[j-2]=='.' || s[i-1]==p[j-2]) take = prev[j];

                    sol = take || noTake;
                } 
                cur[j] = sol;
            }
            prev = cur;
        }

        return prev[n2-1];
    }
};