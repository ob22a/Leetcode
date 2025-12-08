class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        
        vector<int> inc(n,0);
        vector<int> dec(n,0);

        for(int i=0;i<n;++i){
            if(i==0 || security[i-1]<security[i]) continue;
            dec[i]=1+dec[i-1];
        }

        for(int i=n-1;i>=0;--i){
            if(i==n-1 || security[i+1]<security[i]) continue;
            inc[i]=1+inc[i+1];
        }

        vector<int> sol;
        for(int i=0;i<n;++i){
            if(inc[i]>=time && dec[i]>=time) sol.push_back(i);
        }

        return sol;
    }
};