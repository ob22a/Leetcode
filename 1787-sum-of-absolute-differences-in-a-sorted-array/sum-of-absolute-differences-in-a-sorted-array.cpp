class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> preSum(n+1,0);
        for(int i=0;i<n;++i) preSum[i+1]=preSum[i]+nums[i];

        vector<int> sol(n);
        for(int i=0;i<n;++i){
            int left=i*nums[i]-preSum[i];
            int right=(preSum[n]-preSum[i+1])-(n-i-1)*nums[i];
            sol[i]=left+right;
        }
        return sol;
    }
};