class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> allVowels={'a','e','i','o','u','A','E','I','O','U'};
        vector<char> vowels;
        for(char letter:s){
            if(allVowels.count(letter)) vowels.push_back(letter);
        }
        int j=vowels.size()-1;

        for(int i=0;i<s.size();++i){
            if(allVowels.count(s[i])){
                s[i]=vowels[j];
                --j;
            }
        }
        return s;
    }
};
