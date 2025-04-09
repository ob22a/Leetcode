class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> winners;
        unordered_map<int,int> counter;
        for(int num:nums) ++counter[num];

        for(const auto& [number,count]:counter){
            if(count>nums.size()/3) winners.push_back(number);
        }

        return winners;
    }
};