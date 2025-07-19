class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long> preSum(n+1,0);
        for(int i=0;i<n;++i) preSum[i+1]=preSum[i]+nums[i];

        int count=0;
        for(int i=1;i<n;i++){
            if(preSum[i]>=preSum[n]-preSum[i]) count++;
        }
        return count;
    }
};