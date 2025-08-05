class Solution {
public:
    int gcd(int a,int b){
        while(b){
            int temp=a;
            a=b;
            b=temp%b;
        }
        return a;
    }
    bool canMeasureWater(int x, int y, int target) {
        if(x+y<target) return false;
        return target%gcd(x,y)==0;
    }
};