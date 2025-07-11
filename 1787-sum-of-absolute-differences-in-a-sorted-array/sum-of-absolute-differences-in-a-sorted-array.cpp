class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        int preSum=0,total=0;
        for(int num:nums) total+=num;

        vector<int> sol(n);
        for(int i=0;i<n;++i){
            preSum+=nums[i];
            sol[i]=(2*(i+1)-n)*nums[i]+total-2*preSum;
        }
        return sol;
    }
};