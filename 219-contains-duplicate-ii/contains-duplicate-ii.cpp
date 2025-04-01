class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0;
        unordered_set<int> numbers;
        for(int j=0;j<nums.size();++j){
            if(numbers.find(nums[j])!=numbers.end()) return true;
            numbers.insert(nums[j]);
            if(j-i==k){
                numbers.erase(nums[i]);//Since num was not repeated upto j num at i isn't needed 
                ++i; //Sliding the Window
            }
        }
        return false;
    }
};