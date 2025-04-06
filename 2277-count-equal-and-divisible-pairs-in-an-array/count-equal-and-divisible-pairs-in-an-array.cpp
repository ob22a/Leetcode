class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,vector<int>> numIndices;
        for(int i=0;i<nums.size();++i){
            numIndices[nums[i]].push_back(i);
        }
        for (const auto[num,index]:numIndices){
            for(int i=0;i<index.size()-1;++i){
                for(int j=i+1;j<index.size();++j){
                    if((index[i]*index[j])%k==0) ++count;
                }
            }
        }
        return count;
    }
};