class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int flipped=0;
        int maxLen=0;
        for(int i=0,j=0;j<n;++j){
            if(nums[j]==0) ++flipped;
            while(flipped>k){
                if(nums[i++]==0) flipped--;
            }
            maxLen=max(j-i+1,maxLen);
        }
        return maxLen;
    }
};