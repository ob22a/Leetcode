class Solution {
public:
    string removeDuplicates(string s, int k) {
        if(s.size()<k) return s;
        vector<pair<char,int>> stk;
        for(char c:s){
            if(!stk.empty() && stk.back().first==c) stk.back().second++;
            else stk.push_back({c,1});
            if(stk.back().second==k) stk.pop_back();
        }
        string sol="";
        for(const auto&[c,count]:stk){
            sol.append(count,c);
        }
        return sol;
    }
};