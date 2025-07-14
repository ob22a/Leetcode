class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int maxVowels(string s, int k) {
        int n=s.size();
        int maxVowels=0;
        int vowels=0;
        for(int i=0,j=0;j<n;++j){
            if(isVowel(s[j])) ++vowels;
            if(j-i+1>k){
                if(isVowel(s[i++])) --vowels;
            }
            maxVowels=max(maxVowels,vowels);
        }
        return maxVowels;
    }
};