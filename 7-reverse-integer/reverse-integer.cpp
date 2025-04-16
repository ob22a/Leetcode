class Solution {
public:
    int reverse(int x) {
        int reversed_num=0;
        while(x!=0){
            if(x<0 && reversed_num<(INT_MIN-x%10)/10) return 0;
            else if(x>0 &&reversed_num>(INT_MAX-x%10)/10) return 0;
            reversed_num=reversed_num*10+x%10;
            x/=10;
        }
        return reversed_num;
    }
};