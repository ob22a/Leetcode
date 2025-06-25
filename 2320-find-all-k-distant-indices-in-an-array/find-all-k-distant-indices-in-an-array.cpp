class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> sol;
        int n=nums.size(),j=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==key){
                while(j<n){
                    if(abs(j-i)<=k) sol.push_back(j);
                    if(j>i && abs(j-i)>k) break;
                    ++j;
                }
            }
        }
        return sol;
    }
};