class Solution {
public:
    vector<string> sol;
    void helper(string combination,int n,int open,int close){
        if(open==n && close==n){
            sol.push_back(combination);
            return ;
        }
        if(open<n) helper(combination+"(",n,open+1,close);
        if(close<open) helper(combination+")",n,open,close+1);
    }
    vector<string> generateParenthesis(int n) {
        sol.clear();
        helper("",n,0,0);
        return sol;
    }
};