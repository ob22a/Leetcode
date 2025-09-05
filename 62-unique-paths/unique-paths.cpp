class Solution {
public:
    int combination(int n,int r){
        if(r>n-r){
            r=n-r;
        }

        long long result=1;
        for(int i=1;i<=r;i++) result=(result*(n-i+1))/i;
        return result;
    }
    int uniquePaths(int m, int n) {
        /*
            Another method to solve this is to use combinatorics
                C(m-1+n-1,m-1/n-1);
                C(m+n-2,m-1/n-1)
        */

       return combination(m+n-2,m-1);
    }
};