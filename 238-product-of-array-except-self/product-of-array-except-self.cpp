class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> sol(nums.size());
        sol[0]=1;
        for(int i=1;i<nums.size();++i) sol[i]=sol[i-1]*nums[i-1];

        int remaining=1;
        for(int i=nums.size()-1;i>=0;--i){
            sol[i]*=remaining;
            remaining*=nums[i];
        }
        
        return sol;
    }
};