class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int leftSum=0,total=0;
        for(int num:nums) total+=num;
        vector<int> sol;
        
        for(int num:nums){
            sol.push_back(abs((2*leftSum)-total+num));
            leftSum+=num;  
        }
        return sol;
    }
};