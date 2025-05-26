class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size()<3) return -1;
        int maximum=0,minimum=nums[0],other=0;
        for(int num:nums){
            if(num>maximum){
                other=maximum;
                maximum=num;
            }
            else if(num<minimum){
                other=minimum;
                minimum=num;
            }
            else other = num;
        }
        return other;
    }
};