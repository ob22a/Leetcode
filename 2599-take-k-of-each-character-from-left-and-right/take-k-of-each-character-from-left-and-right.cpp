class Solution {
public:
    bool isInvalid(const array<int,3>& window,const array<int,3>& skipAmount){
        for(int i=0;i<3;++i){
            if(window[i]>skipAmount[i]) return false;
        }
        return true;
    }
    int takeCharacters(string s, int k) {
        array<int,3> freq;
        for(char c:s) freq[c-'a']++;
        for(int count:freq){
            if(count<k) return -1;
        }

        array<int,3> skipAmount;
        for(int i=0;i<3;++i) skipAmount[i]=freq[i]-k;

        int i=0,maxLen=0;
        array<int,3> window;
        for(int j=0;j<s.size();++j){
            window[s[j]-'a']++;
            while(!isInvalid(window,skipAmount)){
                window[s[i++]-'a']--;
            }
            maxLen=max(maxLen,j-i+1);
        }
        return s.size()-maxLen;
    }
};