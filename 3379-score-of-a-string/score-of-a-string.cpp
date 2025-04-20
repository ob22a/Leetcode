class Solution {
public:
    int scoreOfString(string s) {
        int score=0,len=s.size();
        for(int i=0;i<len-1;++i) score+=abs(s[i]-s[i+1]);
        return score;
    }
};