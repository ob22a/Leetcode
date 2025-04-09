class Solution {
public:
    bool isPerfectSquare(int num) {
        int left=1, right=num;
        while(right>=left){
            long mid=left+(right-left)/2;
            if(mid*mid==num) return true;
            else if(mid*mid>num) right=mid-1;
            else if(mid*mid<num) left=mid+1;
        }
        return false;
    }
};