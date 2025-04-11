class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> sol(n+1,0);
        for(int i=0;i<=n;++i){
            sol[i]=numBits(i);
        }
        return sol;
    }
    int numBits(int n){
        int count=0;
        while(n>0){
            ++count;
            n=n&(n-1);
        }
        return count;
    }
};
