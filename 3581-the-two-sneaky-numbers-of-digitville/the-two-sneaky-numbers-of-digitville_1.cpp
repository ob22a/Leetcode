class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int> seen;
        vector<int> sol;
        for(int num:nums){
            if(seen.find(num)!=seen.end()){
                sol.push_back(num);
                if(sol.size()==2) break;
            }
            seen.insert(num);
        }
        return sol;
    }
};
