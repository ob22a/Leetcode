class Solution {
public:
    bool equalFrequency(string word) {
        int freq[26]={};
        for(char c:word) freq[c-'a']++;

        for(int i=0;i<26;++i){
            if(freq[i]!=0){
                freq[i]--;
                unordered_set<int> set;
                for(int i=0;i<26;++i){
                    if(freq[i]>0) set.insert(freq[i]);
                }
                if(set.size()==1) return true;
                freq[i]++;
            }
        }
        return false;
    }
};