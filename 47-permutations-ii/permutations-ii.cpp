class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<bool> used(n,false);
        vector<int> perm;
        vector<vector<int>> sol;

        auto bkt = [&](auto&& self,int idx){
            if(idx==n){
                sol.push_back(perm);
                return;
            }

            int lastRemoved=INT_MIN;// Any place holder works as long as it is not equal to a possible value 
            for(int i=0;i<n;++i){
                if(nums[i]==lastRemoved || used[i]) continue;
                used[i]=true;
                perm.push_back(nums[i]);
                self(self,idx+1);
                used[i]=false;
                lastRemoved=perm.back();
                perm.pop_back();
            }
        };

        sort(nums.begin(),nums.end());
        bkt(bkt,0);
        return sol;
    }
};