class Solution {
public:
    int helper(int a,int b,int mod){
        int result=1;
        a%=mod;
        while(b>0){
            if(b%2==1) result=(1LL*result*a)%mod;//Making it long long before multiplication
            a=(1LL*a*a)%mod;
            b/=2;
        }
        return result;
    }
    int superPow(int a, vector<int>& b) {
        int result=1;
        for(int digit:b){
            result=(helper(result,10,1337)*helper(a,digit,1337))%1337;
        }
        return result;
    }
};