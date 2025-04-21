class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()==0) return true;

        int i=0,j=0;
        while(j<t.size()){
            if(i==s.size()-1 && s[i]==t[j]) return true;
            if(s[i]==t[j]){
                ++i;
                ++j;
            }
            else ++j;
        }
        return false;
    }
};