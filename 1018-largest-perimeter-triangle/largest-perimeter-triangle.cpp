class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int i=nums.size()-1,j=nums.size()-2,k=nums.size()-3;
        while(k>=0){
            if(nums[j]+nums[k]>nums[i]) return nums[i]+nums[j]+nums[k];
            --i; --j; --k;
        }
        return 0;
    }
};