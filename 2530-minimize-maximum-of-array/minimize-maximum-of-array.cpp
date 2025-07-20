class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        int sol=0;
        
        for(int i=0;i<n;++i){
            sum+=nums[i];
            int avg=(sum+i)/(i+1);
            sol=max(sol,avg);
        }
        return sol;
    }
};