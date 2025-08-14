class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> sol;
        vector<int> nums;

        auto bkt = [&](auto&& self,int sum,int start){
            if(sum>n) return;
            if(sum==n && nums.size()==k){
                sol.push_back(nums);
                return;
            }

            for(int i=start;i<10;++i){
                nums.push_back(i);
                self(self,sum+i,i+1);
                nums.pop_back();
            }
        };

        bkt(bkt,0,1);
        return sol;
    }
};