class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxLen=0;
        int zeros=0;
        for(int i=0,j=0;j<n;++j){
            zeros+=(nums[j]==0);
            while(zeros>1) zeros-=(nums[i++]==0);
            maxLen=max(maxLen,j-i);
        }
        return maxLen;
    }
};