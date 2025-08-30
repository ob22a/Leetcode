class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>> sol;
        vector<int> path;
        auto bkt = [&] (auto&& self,int idx)->void{
            sol.push_back(path);

            for(int i=idx;i<n;++i){
                if(i>idx && nums[i]==nums[i-1]) continue;
                path.push_back(nums[i]);
                self(self,i+1);
                path.pop_back();
            }
        };

        bkt(bkt,0);
        return sol;
    }
};