class Solution {
public:
    int hammingWeight(int n) {
        int sol=0;
        while(n>0){
            if(n%2==1) sol+=1;
            n/=2;
        }
        return sol;
    }
};
