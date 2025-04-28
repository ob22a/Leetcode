class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> sol;

        unordered_map<int,int>numCount;
        for(int num:nums){
            numCount[num]++;
        }
        set<pair<int,int>,greater<pair<int,int>>> count;
        for(const auto& pair:numCount){
            count.insert({pair.second,pair.first});
        }
        
        int len=0;
        for(const auto&[c,n]:count){
            if(len==k) break;
            sol.push_back(n);
            ++len;
        }
        return sol;
    }
};