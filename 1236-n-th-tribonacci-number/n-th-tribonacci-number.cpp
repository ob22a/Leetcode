class Solution {
public:
    int tribonacci(int n) {
        int first=0,second=1,third=1;
        if(n<1) return n;
        if(n==2) return 1;
        
        for(int i=3;i<=n;++i){
            int temp=third;
            third+=first+second;
            first=second;
            second=temp;
        }
        return third;
    }
};