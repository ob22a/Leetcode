#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (seen.count(complement)) { 
                std::vector<int> result = {seen[complement], i};
                return result;
            }
            seen[nums[i]] = i; 
        }
        return {};
    }
};
