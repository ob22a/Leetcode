class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> numIdx;
        for(int i=0;i<n;++i) numIdx[arr[i]]=i;

        vector<vector<int>> dp(n,vector<int>(n,2));
        int sol=0;

        for(int last=2;last<n;++last){
            for(int before=1;before<last;++before){
                int first = arr[last] - arr[before];
                if(numIdx.find(first)!=numIdx.end() && numIdx[first]<before){
                    int idx = numIdx[first];
                    dp[last][before] = dp[before][idx] + 1;
                }
                sol = max(sol,dp[last][before]);
            }
        }

        return sol>=3?sol:0;
    }
};