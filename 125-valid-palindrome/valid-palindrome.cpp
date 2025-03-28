class Solution {
public:
    void tolower(string& s){
        for(auto it=s.begin();it<s.end();++it){
            if('A'<=*it && *it <= 'Z') (*it)+=32;
            else if(('a'<=*it && *it<='z')||('0'<=*it && *it<='9')) continue;
            else (*it)=' ';
        }
    }
    bool isPalindrome(string s) {
        this->tolower(s);
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=' ' && s[j]!=' '){
                if(s[i]!=s[j]) return false;
                ++i;
                --j;
            }
            if(s[i]==' ') ++i;
            if(s[j]==' ') --j;
        }
        return true;
    }
};