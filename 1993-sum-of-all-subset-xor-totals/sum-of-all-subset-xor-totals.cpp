class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int result=0;
        for(int i=0;i<(1<<nums.size());++i){
            int val=0;
            for(int j=0;j<nums.size();++j){
                if(i&(1<<j)) val^=nums[j];
            }
            result+=val;
        }
        return result;
    }
};