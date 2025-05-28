class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        array<int,26> alpha={};
        for(char c:p) alpha[c-'a']++;
        
        vector<int>sol;
        array<int,26> subString={};
        int left=0,right=0;

        while(right<s.size()){
            int idx=s[right]-'a';
            if(alpha[idx]==0){
                subString.fill(0);
                left=++right;
            }
            else{
                subString[idx]++;
                while(subString[idx]>alpha[idx]){
                    subString[s[left]-'a']--;
                    ++left;
                }
                if(subString==alpha){
                    sol.push_back(left);
                    subString[s[left]-'a']--;
                    ++left;
                }
                ++right;
            }
        }
        return sol;
    }
};