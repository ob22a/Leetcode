class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> sol;
        int n=nums.size();
        sol.reserve(n);

        sort(nums.begin(),nums.end());
        long long total = 0;
        long long sum = 0;
        for(int num:nums) total+=num;

        for(int i=n-1;i>=0;--i){
            if(sum>total) break;
            sol.push_back(nums[i]);
            sum+=nums[i];
            total-=nums[i];
        }

        return sol;
    }
};