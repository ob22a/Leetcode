class Solution {
public:
    int sum_of_squares(int n){
        int result=0;
        while(n>0){
            int last_digit=n%10;
            result+=last_digit*last_digit;
            n/=10;
        }
        return result;
    }
    
    bool isHappy(int n) {
        int slow=n;
        int fast=sum_of_squares(n);
        while(fast!=1 && fast!=slow){
            slow=sum_of_squares(slow);
            fast=sum_of_squares(sum_of_squares(fast));
        }
        return fast==1;
    }
};