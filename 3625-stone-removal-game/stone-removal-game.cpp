class Solution {
public:
    bool canAliceWin(int n) {
        int i=10;
        while (n>=0){
            if(n-i<0) return false;
            n-=i+--i;
            --i;
        }
        return true;
    }
};