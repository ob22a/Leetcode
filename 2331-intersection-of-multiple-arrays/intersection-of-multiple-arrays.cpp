class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int> count;
        for(const auto& vec:nums){
            for(const int& num:vec){
                count[num]++;
            }
        }
        vector<int> sol;
        for(const auto& p:count){
            if(p.second==nums.size()) sol.push_back(p.first);
        }
        sort(sol.begin(),sol.end());
        return sol;
    }
};