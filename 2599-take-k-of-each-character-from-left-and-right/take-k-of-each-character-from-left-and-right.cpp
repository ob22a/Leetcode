class Solution {
public:
    int takeCharacters(string s, int k) {
        array<int,3> freq;
        for(char c:s) freq[c-'a']++;
        for(int count:freq){
            if(count<k) return -1;
        }

        int n=s.size();
        int sol=n;
        for(int i=0,j=0;j<n;++j){
            freq[s[j]-'a']--;
            while(freq[s[j]-'a']<k){
                freq[s[i++]-'a']++;
            }
            sol=min(sol,n-(j-i+1));
        }
        return sol;
    }
};