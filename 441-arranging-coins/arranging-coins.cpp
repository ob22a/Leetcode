class Solution {
public:
    int arrangeCoins(int n) {
        if(n==1) return 1;
        for(long i=1;i<=n;++i){
            long long total=i*(i+1)/2;
            long long nextTotal=(i+1)*(i+2)/2;
            if(total==n || nextTotal>n) return i;
        }
        return -1;
    }
};