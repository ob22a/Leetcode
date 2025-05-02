class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int preSum=nums[0],i;
        unordered_set<int> seen;
        for(i=0;i<nums.size()-1;++i){
            if(nums[i+1]==nums[i]+1) preSum+=nums[i+1];
            else break;
        }
        for(i;i<nums.size();++i){
            seen.insert(nums[i]);
        }

        while(true){
            if(!seen.count(preSum)) return preSum;
            ++preSum;
        }
        
        return -1;
    }
};