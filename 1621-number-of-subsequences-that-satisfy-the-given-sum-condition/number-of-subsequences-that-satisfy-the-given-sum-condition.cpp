class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        int MOD = 1e9 +7;
        sort(nums.begin(),nums.end());
        vector<int> power(n, 1);
        for (int i=1; i<n; i++) power[i] = (power[i-1]*2LL) % MOD;

        int l=0, r=n-1;
        long long sol=0;
        while(l<=r){
            if(nums[l]+nums[r]>target) --r;
            else{
                sol =(sol+power[r-l]) % MOD;
                l++;
            }
        } 
        return sol%MOD;
    }
};