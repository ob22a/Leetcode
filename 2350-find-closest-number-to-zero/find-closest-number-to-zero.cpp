class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int sol=nums[0];
        for(int num:nums){
            if(abs(num)<abs(sol)){
                sol=num;
            }
            else if(abs(num)==abs(sol)){
                sol=max(sol,num);
            }
        }
        return sol;
    }
};