class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>sol;

        auto bkt=[&](auto&& self,int open,int close,string s){
            if(s.size()==(2*n)){
                sol.push_back(s);
                return;
            }

            if(open<n) self(self,open+1,close,s+"(");
            if(close<open) self(self,open,close+1,s+")");
        };

        bkt(bkt,0,0,"");
        return sol;
    }
};