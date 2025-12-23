class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        double ans = 1e9;
        int i=0,j=nums.size()-1;
        while(i<j){
            double val =(nums[i]+nums[j])/2.0;
            ans=min(ans,val);
            ++i; --j;
        }
        return ans;
    }
};