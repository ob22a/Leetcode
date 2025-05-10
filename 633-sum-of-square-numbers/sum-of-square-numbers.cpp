class Solution {
public:
    bool judgeSquareSum(int c) {
        int small=0,large=static_cast<int>(sqrt(c));
        if(large*large==c) return true;

        while(large>=small){
            long long sum=1LL*small*small+large*large;
            if(sum==c) return true;
            if(sum>c) large--;
            else small++;
        }
        return false;
    }
};