#include<cmath>
class Solution {
public:
    int fib(int n) {
       double golden_ratio=(1+sqrt(5))/2;
       double complement=(1-sqrt(5))/2;
       return round((pow(golden_ratio,n)-pow(complement,n))/sqrt(5));
    }
};