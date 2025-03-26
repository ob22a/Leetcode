class Solution {
public:
    int mySqrt(int x) {
        int l=0;
        int r=x;
        while(r>=l){
            long m=l+(r-l)/2;
            if(m*m==x) return m;            
            else if(m*m<x) l=m+1;
            else r=m-1;
        }
        return r;
    }
};