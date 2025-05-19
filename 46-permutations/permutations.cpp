class Solution {
public:
    void backtrack(vector<int> nums,vector<bool> seen,vector<int> res,vector<vector<int>>& sol){
        if(res.size()==nums.size()){
            sol.push_back(res);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(seen[i]) continue;
            seen[i]=true;
            res.push_back(nums[i]);
            backtrack(nums,seen,res,sol);
            res.pop_back();
            seen[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> res;
        vector<bool> seen(nums.size(),false);
        backtrack(nums,seen,res,sol);
        return sol;
    }
};