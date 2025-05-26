class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int alphabets[26];
        for(char c:words[0]) alphabets[c-'a']++;

        for(int i=1;i<words.size();++i){
            int alpha[26]={};
            for(char c:words[i]){
                alpha[c-'a']++;
            }
            for(int j=0;j<26;++j) alphabets[j]=min(alphabets[j],alpha[j]);
        }
        vector<string> result;
        for(int i=0;i<26;++i){
            while(alphabets[i]>0){
                char c = i+'a';
                string s; s.push_back(c);
                result.push_back(s);
                --alphabets[i];
            }
        }
        return result;
    }
};