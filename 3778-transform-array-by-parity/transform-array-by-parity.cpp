class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        //Swap even and odd make even come first
        int i=0;
        for(int j=0;j<nums.size();++j){
            if(nums[j]%2==0){
                swap(nums[i],nums[j]);
                ++i;
            }
        }
        //Make even 0 odd 1
        for(int& num:nums){
            if(num%2==0) num=0;
            else num=1;
        }
        return nums;
    }
};