class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num==1) return false;
        long count=1;
        for(int i=2;i<=num/2;++i){
            if(num%i==0) count+=i;
        }
        return count==num;
    }
};
