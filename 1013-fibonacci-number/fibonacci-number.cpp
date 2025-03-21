class Solution {
public:
    int fib(int n) {
        if(n<2){
            return n;
        }
        int a=0,b=1;
        for(int j=2;j<=n;++j){
            int temp=a;
            a=b;
            b=temp+b;
        }
        return b;
    }
};