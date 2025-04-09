class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        return 1162261467%n==0;//the maximum power of 3 in int
    }
};