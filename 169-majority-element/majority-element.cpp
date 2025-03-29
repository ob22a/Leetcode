class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> counter;
        
        for(int num:nums){
            counter[num]++; //c++ initializes missing keys with 0 by default so no need for if else.
        }
       
        for(auto pair:counter){
            if(pair.second>nums.size()/2){
                return pair.first;
            }
        }
        return -1;
    }
};