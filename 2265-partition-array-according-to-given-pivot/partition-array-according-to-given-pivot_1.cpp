class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> sol;
        for(int num:nums){
            if(num<pivot) sol.push_back(num);
        }
        for(int num:nums){
            if(num==pivot) sol.push_back(num);
        }
        for(int num:nums) {
            if(num>pivot) sol.push_back(num);
        }
        return sol;
    }
};
