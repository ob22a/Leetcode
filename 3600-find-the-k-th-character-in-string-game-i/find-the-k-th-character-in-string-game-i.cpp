class Solution {
public:
    int countOnes(int n){
        int result=0;
        while(n){
            n&=n-1;
            ++result;
        }
        return result;
    }
    char kthCharacter(int k) {
        return 'a'+countOnes(k-1);
    }
};