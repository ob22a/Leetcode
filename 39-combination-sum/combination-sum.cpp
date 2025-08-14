class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>> sol;
        vector<int>nums;

        auto backtrack = [&](auto&& self,int sum,int idx){
            if(sum>target) return;
            if(sum==target){
                sol.push_back(nums);
                return;
            }
            for(int i=idx;i<n;++i){
                sum+=candidates[i];
                nums.push_back(candidates[i]);
                self(self,sum,idx);
                idx+=1;
                sum-=candidates[i];
                nums.pop_back();
            }
        };
        
        sort(candidates.begin(),candidates.end());
        backtrack(backtrack,0,0);
        return sol;
    }
};