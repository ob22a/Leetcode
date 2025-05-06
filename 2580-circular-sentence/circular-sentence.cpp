class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        string firstWord,prevWord,word;
        ss>>firstWord;
        prevWord=firstWord;

        while(ss>>word){
            if(prevWord.back()!=word.front()) return false;
            prevWord=word;
        }

        return firstWord.front()==prevWord.back();
    }
};