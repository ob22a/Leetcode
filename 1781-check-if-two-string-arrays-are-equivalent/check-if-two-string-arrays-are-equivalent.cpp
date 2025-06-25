class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int wordIdx1=0,wordIdx2=0,i=0,j=0;
        while(i<word1.size() && j<word2.size()){
            if(wordIdx1==word1[i].size()){
                ++i; wordIdx1=0;
            } 
            if(wordIdx2==word2[j].size()){
                ++j; wordIdx2=0;
            } 
            if(i==word1.size() && j==word2.size()) break;
            else if(i==word1.size() || j==word2.size()) return false;
            else if(word1[i][wordIdx1]!=word2[j][wordIdx2]) return false;
            ++wordIdx1; ++wordIdx2;
        }
        return true;
    }
};