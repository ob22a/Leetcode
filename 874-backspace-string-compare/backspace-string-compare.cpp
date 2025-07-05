class Solution {
public:
    bool backspaceCompare(string s, string t) {
        if(s==t) return true; //early termination

        int i=s.size()-1,j=t.size()-1;
        while(i>=0 || j>=0){
            int sSkip=0,tSkip=0;
            while(i>=0){
                if(s[i]=='#'){
                    ++sSkip;
                    --i;
                }
                else if(sSkip>0){
                    --i;
                    sSkip--;
                }
                else break;
            }
            while(j>=0){
                if(t[j]=='#'){
                    ++tSkip;
                    --j;
                }
                else if(tSkip>0){
                    --j;
                    --tSkip;
                }
                else break;
            }

            if((i>=0)!=(j>=0)) return false;
            if(i>=0 && j>=0 && s[i]!=t[j]) return false;

            --i; --j;
        }
        return true;
    }
};