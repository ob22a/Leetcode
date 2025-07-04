class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> sol;
        int count=0;
        for(int num:nums){
            if(num<pivot) sol.push_back(num);
            else if(num==pivot) ++count;
        }
        for(int i=0;i<count;++i) sol.push_back(pivot);
        for(int num:nums) {
            if(num>pivot) sol.push_back(num);
        }
        return sol;
    }
};
