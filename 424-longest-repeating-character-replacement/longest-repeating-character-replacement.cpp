class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxLen=0;
        int maxFreq=0;
        array<int,26> window={};
        
        for(int i=0,j=0;j<n;++j){
            window[s[j]-'A']++;
            maxFreq=max(maxFreq,window[s[j]-'A']);

            while((j-i+1) - maxFreq > k) window[s[i++]-'A']--;
            maxLen=max(maxLen,j-i+1);
        }
        return maxLen;
    }
};