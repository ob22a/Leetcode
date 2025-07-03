class Solution {
public:
    char kthCharacter(int k) {
        string s="0";
        int noOperations = log10(k)/log10(2);
        for(int i=0;i<=noOperations;++i){
            string mod="";
            for(char c:s) mod.push_back(c+1);
            s+=mod;
            cout<<s<<endl;
        }
        return 'a'+(s[k-1]-'0');
    }
};