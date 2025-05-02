class Solution {
public:
    int numDigits(int num){
        int count=0;
        while(num>0){
            ++count;
            num/=10;
        }
        return count;
    }
    int alternateDigitSum(int n) {
        if(n<10) return n;

        int sum=0;
        int sign=(numDigits(n)%2==0)?-1:1;
        while(n>0){
            sum+=sign*n%10;
            sign*=-1;
            n/=10;
        }
        return sum;
    }
};