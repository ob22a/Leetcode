class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> seen={nums[0]};
        int j=1;
        for(int i=1;i<nums.size();++i){
            if(seen.count(nums[i])==0){
                seen.insert(nums[i]);
                nums[j]=nums[i];
                ++j;
            }
        }
        return seen.size();
    }
};