class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> counter;
        
        for(int num:nums){
            if(counter.count(num)) counter[num]+=1;
            else counter[num]=1;
        }
       
        for(auto pair:counter){
            if(pair.second>nums.size()/2){
                return pair.first;
            }
        }
        return -1;
    }
};