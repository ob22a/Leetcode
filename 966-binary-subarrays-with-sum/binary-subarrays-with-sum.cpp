class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> preCount(nums.size()+1);
        preCount[0]=1;
        
        int count=0,sum=0;        
        for(int num:nums){
            sum+=num;
            if(sum-goal>=0) count+=preCount[sum-goal];
            preCount[sum]++;
        }

        return count;
    }
};