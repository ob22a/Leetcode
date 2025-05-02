class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNumbers(1);
        uglyNumbers[0]=1;
        int i2=0,i3=0,i5=0;
        while(uglyNumbers.size()<n){
            int next2=2*uglyNumbers[i2];
            int next3=3*uglyNumbers[i3];
            int next5=5*uglyNumbers[i5];

            int minimum=min(next2,min(next3,next5));
            uglyNumbers.push_back(minimum);

            if(next2==minimum) ++i2;
            if(next3==minimum) i3++;
            if(next5==minimum) i5++;
        }
        return uglyNumbers[n-1];
    }
};