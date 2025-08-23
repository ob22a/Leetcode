class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> sol;
        vector<int> a;
        auto bkt = [&](auto&& self, int idx){
            if(idx>=n){
                sol.push_back(a);
                return;
            }
            a.push_back(nums[idx]);
            self(self,idx+1);
            a.pop_back();
            self(self,idx+1);
        };

        bkt(bkt,0);
        return sol;
    }
};