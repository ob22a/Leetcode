class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>> sol;
        for(int i=0;i<nums.size()-2;++i){
            if(i>0 && nums[i]==nums[i-1]) continue;

            int num=nums[i];
            int l=i+1,r=nums.size()-1;

            while(l<r){
                int comp=nums[l]+nums[r];
                if(comp==-num){
                    sol.push_back({num,nums[l],nums[r]});
                    while(l<r && nums[l]==nums[l+1]) ++l;
                    while(l<r && nums[r]==nums[r-1]) --r;
                    ++l;
                    --r;
                }
                else if(comp>-num) --r;
                else ++l;
            }
        }
        return sol;
    }
};