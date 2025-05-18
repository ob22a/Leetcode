class Solution {
public:
    string removeKdigits(string num, int k) {
        string sol;
        for(char c:num){
            while(k>0 && !sol.empty() && sol.back()>c){
                sol.pop_back();
                --k;
            }
            sol.push_back(c);
        }
        while(k>0 && !sol.empty()){
                sol.pop_back();
                --k;
            }
        
        int i=0;
        while(i<sol.size() && sol[i]=='0') ++i;

        sol = sol.substr(i);

        return sol.empty()?"0":sol;
    }
};