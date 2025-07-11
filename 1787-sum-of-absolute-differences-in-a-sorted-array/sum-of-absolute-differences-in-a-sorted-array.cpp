class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> preSum(n+1,0);
        for(int i=0;i<n;++i) preSum[i+1]=preSum[i]+nums[i];

        vector<int> sol(n);
        for(int i=0;i<n;++i){
            sol[i]=(2*(i+1)-n)*nums[i]+preSum[n]-2*preSum[i+1];
        }
        return sol;
    }
};