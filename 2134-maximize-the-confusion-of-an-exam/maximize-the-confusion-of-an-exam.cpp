class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        int t=0,f=0;
        int maxLen=0;
        for(int i=0,j=0;j<n;++j){
            if(answerKey[j]=='T') ++t;
            else ++f;
            while(j-i+1 - max(t,f)>k){
                if(answerKey[i++]=='T') t--;
                else --f;
            }
            maxLen=max(maxLen,j-i+1);
        }
        return maxLen;
    }
};