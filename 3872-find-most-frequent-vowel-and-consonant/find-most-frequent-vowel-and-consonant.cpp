class Solution {
public:
    int maxFreqSum(string s) {
        bool isVowel[26]={};
        isVowel['a'-'a']=true;
        isVowel['e'-'a']=true;
        isVowel['i'-'a']=true;
        isVowel['o'-'a']=true;
        isVowel['u'-'a']=true;    

        int counter[26]={};
        int maxVow=0,maxCon=0;
        for(char c:s){
            int i=c-'a';
            counter[i]++;
            if(isVowel[i]) maxVow=max(maxVow,counter[i]);
            else maxCon=max(maxCon,counter[i]);
        }
        return maxVow+maxCon;
    }
};