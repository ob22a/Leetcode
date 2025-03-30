class Solution {
public:
    int hammingWeight(int n) {
        int sol=0;
        while(n>0){
            n&=(n-1); //This would work because n-1 has 1 less 1 than n and this reduces the number faster to 0
            ++sol;
        }
        return sol;
    }
};