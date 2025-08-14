class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> sol;
        vector<int> nums;

        auto bkt= [&](auto&& self,int start){
            if(nums.size()==k){
                sol.push_back(nums);
                return;
            }

            for(int i=start;i<=n;++i){
                nums.push_back(i);
                self(self,i+1);
                nums.pop_back();
            }
        };

        bkt(bkt,1);
        return sol;
    }
};