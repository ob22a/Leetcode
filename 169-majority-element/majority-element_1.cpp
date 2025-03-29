class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> counter;
        
        for(int num:nums){
            counter[num]++; //c++ initializes missing keys with 0 by default so no need for if else.
        }
       
        for(const auto pair:counter){//adding const avoids copying and improves performance
            if(pair.second>nums.size()/2){
                return pair.first;
            }
        }
        return -1;
    }
};
