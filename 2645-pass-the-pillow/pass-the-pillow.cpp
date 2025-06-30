class Solution {
public:
    int passThePillow(int n, int time) {
        int full_round=time/(n-1),rem=time%(n-1);
        if(full_round%2==0) return 1+rem;
        return n-rem;
    }
};