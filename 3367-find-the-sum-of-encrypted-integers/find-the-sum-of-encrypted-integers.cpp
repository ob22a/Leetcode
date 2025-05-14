class Solution {
public:
    pair<int,int> largestDigit(int num){
        int result=0;
        int len=0;
        while(num>0){
            result=max(result,num%10);
            num/=10;
            ++len;
        }
        return {result,len};
    }
    int sumOfEncryptedInt(vector<int>& nums) {
        int sol=0;
        for(int num:nums){
            pair<int,int> p=largestDigit(num);
            int largest=p.first,length=p.second;
            int mul=1;
            for(int i=1;i<length;++i){
                mul*=10;
                ++mul;
            }
            sol+=mul*largest;
        }
        return sol;
    }
};