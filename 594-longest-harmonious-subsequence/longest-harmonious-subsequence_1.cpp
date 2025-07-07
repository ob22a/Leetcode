class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> counter;
        for(int num:nums) ++counter[num];
        int maxLength=0;

        for(const auto&[number,count]:counter){
            if(counter.count(number+1)){ 
                maxLength=max(maxLength,count+counter[number+1]);
            }
        }
        return maxLength;
    }
};
