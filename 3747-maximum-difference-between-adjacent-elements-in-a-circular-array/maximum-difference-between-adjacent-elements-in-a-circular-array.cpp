class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int diff=abs(nums[0]-nums.back());
        for(int i=0;i<nums.size()-1;++i) diff=max(diff,abs(nums[i]-nums[i+1]));
        return diff;
    }
};