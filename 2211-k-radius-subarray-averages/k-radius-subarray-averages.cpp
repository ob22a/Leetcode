class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        long long preSum=0;
        int len=2*k+1;
        vector<int> sol(n,-1);
        for(int i=0,j=0;j<n;++j){
            preSum+=0ll+nums[j];
            if((j-i+1)>len) preSum-=nums[i++];
            if((j-i+1)==len) sol[j-k]=preSum/len;
        }
        return sol;
    }
};