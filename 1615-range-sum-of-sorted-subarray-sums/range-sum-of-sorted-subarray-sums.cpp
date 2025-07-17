class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int MOD=1e9+7;
        vector<long long> sum;
        for(int i=0;i<nums.size();++i){
            long long val=nums[i];
            for(int j=i+1;j<=nums.size();++j){
                sum.push_back(val);
                if(j!=nums.size()) val+=nums[j];
            }
        }
        sort(sum.begin(),sum.end());
        long long ans=0;
        for(int i=left-1;i<right;++i)ans+=sum[i];

        return ans%MOD;
    }
};