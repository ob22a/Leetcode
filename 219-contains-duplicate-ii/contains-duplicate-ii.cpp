class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> numIndex;

        for(int i=0;i<nums.size();++i){
            if(numIndex.count(nums[i])){
                if(i-numIndex[nums[i]]<=k) return true;
            }
            numIndex[nums[i]]=i;
        }

        return false;
    }
};