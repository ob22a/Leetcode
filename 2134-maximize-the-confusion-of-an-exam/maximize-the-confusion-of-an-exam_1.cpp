class Solution {
public:
    int replaceChar(string answerKey,int k,char c){
        int n=answerKey.size();
        int changes=0;
        int maxLen=0;
        for(int i=0,j=0;j<n;++j){
            if(answerKey[j]==c) changes++;
            while(changes>k){
                if(answerKey[i++]==c) changes--;
            }
            maxLen=max(maxLen,j-i+1);
        }
        return maxLen;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int sol=max(replaceChar(answerKey,k,'T'),replaceChar(answerKey,k,'F'));
        return sol;
    }
};
