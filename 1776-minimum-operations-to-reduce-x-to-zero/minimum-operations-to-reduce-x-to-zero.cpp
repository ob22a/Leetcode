class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // Thinking in reverse
        int total=0;
        for(int num:nums) total+=num;

        vector<int> preSum(nums.size());
        preSum[0]=nums[0];
        for(int i=1;i<nums.size();++i) preSum[i]=preSum[i-1]+nums[i];
        
        int i=0,sum=0,remaining=total-x;
        int len=-1;
        for(int j=0;j<nums.size();++j){
            sum+=nums[j];
            while(sum>remaining && i<=j) sum-=nums[i++];
            if(sum==remaining) len=max(len,j-i+1);
        }
        return (len==-1)?len:nums.size()-len;
    }
};