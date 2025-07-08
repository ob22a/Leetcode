class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();

        int len=n+1;
        int sum=0;
        for(int i=0,j=0;j<n;++j){
            sum+=nums[j];
            while(sum>=target){
                len=min(len,j-i+1);
                sum-=nums[i++];
            }
        }
        return (len==n+1)?0:len;
    }
};