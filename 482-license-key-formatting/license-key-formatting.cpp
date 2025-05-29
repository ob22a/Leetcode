class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int len=0;
        string filtered="";
        for(char c:s){
            if(c!='-') filtered.push_back(toupper(c));
        }

        string sol="";
        for(int r=filtered.size()-1;r>=0;--r){
            ++len;
            sol.push_back(filtered[r]);
            if(len==k && r!=0){
                len=0;
                sol.push_back('-');
            }
        }
        reverse(sol.begin(),sol.end());
        return sol;
    }
};