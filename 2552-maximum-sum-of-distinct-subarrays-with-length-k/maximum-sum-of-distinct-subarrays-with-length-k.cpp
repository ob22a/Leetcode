class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> distinct;
        long long sum=0;
        long long preSum=0;
        for(int i=0,j=0;j<n;++j){
            preSum+=0ll+nums[j];
            distinct[nums[j]]++;
            while(j-i+1>k){
                preSum-=nums[i];
                if(--distinct[nums[i]]==0) distinct.erase(nums[i]);
                i++;
            }
            if(j-i+1==k && distinct.size()==k) sum=max(preSum,sum);
        }
        return sum;
    }
};