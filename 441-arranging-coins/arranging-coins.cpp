class Solution {
public:
    int arrangeCoins(int n) {
        int low=0,high=n;
        while(high>=low){
            long mid=low+(high-low)/2;
            long total=mid*(mid+1)/2;
            if(total==n) return mid;
            else if(total>n) high=mid-1;
            else low=mid+1;
        }
        return high;
    }
};