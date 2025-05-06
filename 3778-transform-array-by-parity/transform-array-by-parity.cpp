class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        //Swap even and odd make even come  and set it to 0 and odd 1
        int i=0;
        for(int j=0;j<nums.size();++j){
            if(nums[j]%2==0){
                swap(nums[i],nums[j]);
                nums[i]=0;
                ++i;
            }
            else nums[j]=1;
        }
        return nums;
    }
};