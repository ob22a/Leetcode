class Solution {
public:
    // Using the formula for digital root
    int addDigits(int num) {
        if(num==0) return 0;
        return 1+(num-1)%9;
    }
};