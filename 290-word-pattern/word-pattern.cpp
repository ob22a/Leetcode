class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string letterMapping[26];
        unordered_map<string,char> wordMapping;
        string word;
        for(char c:pattern){
            if(!(ss>>word)) return false;
            if(!letterMapping[c-'a'].empty()){
                if(letterMapping[c-'a']!=word) return false;
            }
            else{
                if(wordMapping.count(word)) return false;
                letterMapping[c-'a']=word;
                wordMapping[word]=c;
            }
        }
        if(ss>>word) return false;

        return true;
    }
};