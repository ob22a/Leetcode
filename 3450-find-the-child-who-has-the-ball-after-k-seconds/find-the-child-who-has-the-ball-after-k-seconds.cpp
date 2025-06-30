class Solution {
public:
    int numberOfChild(int n, int k) {
        int full_round=k/--n;
        int rem=k%n;
        if(full_round%2==0) return rem;
        return n-rem;
    }
};