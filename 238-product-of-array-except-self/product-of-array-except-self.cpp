class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> sol(nums.size());
        vector<int>rpp(nums.size()); // REVERSE PREFIX PRODUCT 
        for(int i=nums.size()-1;i>=0;--i){
            rpp[i]=((i==nums.size()-1))?nums[i]:rpp[i+1]*nums[i];
        }

        int preProduct=1;
        for(int i=0;i<nums.size();++i){
            sol[i]=(i!=nums.size()-1)?rpp[i+1]*preProduct:preProduct;
            preProduct*=nums[i];
        }
        return sol;
    }
};