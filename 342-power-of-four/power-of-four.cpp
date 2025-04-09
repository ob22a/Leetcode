class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && 1073741824%n==0 && n%3==1; //Using the maximum power of 4 in int range and making sure the number isn't 2 or its multiples 
    }
};