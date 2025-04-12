class Solution {
public:
    string removeStars(string s) {
        string sol="";
        for(char a:s){
            if(!s.empty() && a=='*') sol.pop_back();
            else sol.push_back(a);
        }
        return sol;
    }
};