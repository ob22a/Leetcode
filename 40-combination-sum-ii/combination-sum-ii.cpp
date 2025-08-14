class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>> sol;
        vector<int> nums;

        auto bkt=[&](auto&& self,int sum,int idx){
            if(sum>target) return;
            if(sum==target){
                sol.push_back(nums);
                return;
            }
            for(int i=idx;i<n;++i){
                if(i>idx && candidates[i]==candidates[i-1]) continue;

                nums.push_back(candidates[i]);
                self(self,sum+candidates[i],i+1);
                nums.pop_back();
            }
        };

        sort(candidates.begin(),candidates.end());
        bkt(bkt,0,0);
        return sol;
    }
};