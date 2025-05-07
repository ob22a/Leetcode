class Solution {
public:
    int wordToNum(string word){
        int val=0;
        for(int i=0;i<word.size();++i){
            val*=10;
            val+=word[i]-'a';
        }
        return val;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return wordToNum(firstWord)+wordToNum(secondWord)==wordToNum(targetWord);
    }
};