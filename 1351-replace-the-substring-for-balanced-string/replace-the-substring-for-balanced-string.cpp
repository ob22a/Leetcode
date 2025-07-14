class Solution {
public:
    bool isValid(int extra[4]){
        return extra[0]<=0 && extra[1]<=0 && extra[2]<=0 && extra[3]<=0;
    }
    int index(char c){
        // let idx 0->E 1->Q 2->R 3->W
        if(c=='E') return 0;
        else if(c=='Q') return 1;
        else if(c=='R') return 2;
        return 3;
    }
    int balancedString(string s) {
        int n=s.size();
        
        int freq[4]={};
        for(char c:s) freq[index(c)]++;
        int target=n/4;
        
        int extra[4]={};
        bool needChange[4]={};
        for(int i=0;i<4;++i){
            if(freq[i]>target){
                extra[i]=freq[i]-target;
                needChange[i]=true;
            }
        }

        if(isValid(extra)) return 0;

        int minLen=n+1;
        for(int i=0,j=0;j<n;++j){
            if(needChange[index(s[j])]) extra[index(s[j])]--;
            while(isValid(extra)){
                minLen=min(minLen,j-i+1);
                if(needChange[index(s[i])]) extra[index(s[i])]++;
                i++;
            }
        }
        return minLen;
    }
};