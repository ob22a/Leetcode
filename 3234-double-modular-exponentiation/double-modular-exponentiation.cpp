class Solution {
public:
    int FME(int a,int b, int mod){
        int result=1,power=a%mod;
        while(b>0){
            if(b&1) result=(1LL*result*power)%mod;
            power=(1LL*power*power)%mod;
            b>>=1;
        }
        return result;
    }
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int>sol;
        int len=variables.size();
        for(int i=0;i<len;++i){
            int a=variables[i][0],b=variables[i][1],c=variables[i][2],m=variables[i][3];
            int first=FME(a,b,10);
            int second=FME(first,c,m);

            if(second==target) sol.push_back(i);
        }
        return sol;
    }
};