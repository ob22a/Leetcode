class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxLen=0;
        array<int,26> letters={};
        for(char c:s) letters[c-'A']++;
        
        for(char cur='A';cur<='Z';++cur){
            if(letters[cur-'A']==0) continue;
            array<int,26> window={};
            int changed=0;
            for(int i=0,j=0;j<n;++j){
                if(s[j]!=cur) changed++;
                while(k<changed){
                    if(cur!=s[i++])changed--;
                }
                maxLen=max(maxLen,j-i+1);
            }
        }
        return maxLen;
    }
};
