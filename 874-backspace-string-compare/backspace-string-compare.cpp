class Solution {
public:
    void helper(string s,string &a){
        for(char c:s){
            if(c=='#'){
                if(!a.empty()) a.pop_back();
            }
            else a.push_back(c);
        }
    }
    bool backspaceCompare(string s, string t) {
        string a="",b="";
        helper(s,a); helper(t,b);
        return a==b;
    }
};