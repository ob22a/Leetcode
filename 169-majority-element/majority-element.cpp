class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int max=0;
        int sol=0;
        unordered_map<int,int> counter;
        
        for(int num:nums){
            if(counter.count(num)) counter[num]+=1;
            else counter[num]=1;
        }
       
        for(auto pair:counter){
            if(pair.second>max){
                sol=pair.first;
                max=pair.second;
            };
        }
        
        return sol;
    }
};