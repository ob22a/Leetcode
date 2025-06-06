class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> count(nums.size(),0);
        for(int num:nums) count[num]++;

        vector<int> sol;
        for(int i=0;i<count.size();++i){
            if(count[i]>1) sol.push_back(i);
        }
        return sol;
    }
};
