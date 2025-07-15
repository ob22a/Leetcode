class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> indices;
        for(int i=0;i<nums.size();++i){
            indices[nums[i]].push_back(i);
        }

        vector<long long> sol(n,0);
        for(const auto&[_,arr]:indices){
            int n=arr.size();
            long long total=0,preSum=0;
            for(int num:arr) total+=0ll+num;
            
            for(int i=0;i<n;++i){
                preSum+=arr[i];
                sol[arr[i]]=total-(2*preSum)+(1ll*arr[i]*(2*i+2-n));
            }
        }
        return sol;
    }
};