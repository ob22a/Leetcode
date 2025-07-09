class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        vector<int> preSum(n+1,0);
        for(int i=0;i<nums.size();++i){
            preSum[i+1]=preSum[i]+nums[i];
        }

        int minSum=INT_MAX;
        for(int start=0;start<n;++start){
            for(int len=l;len<=r;++len){
                int end=start+len-1;
                if(end>=n) break;
                int sum=preSum[end+1]-preSum[start];
                if(sum>0) minSum=min(minSum,sum);
            }
        }
        return (minSum==INT_MAX)?-1:minSum;
    }
};