class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int num:nums) total+=num;

        int sum=0;
        for(int i=0;i<n;++i){
            if(sum==total-sum-nums[i]) return i;
            sum+=nums[i];
        }
        return -1;
    }
};