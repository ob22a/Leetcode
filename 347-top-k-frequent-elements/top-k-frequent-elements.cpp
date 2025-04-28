class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> sol;

        unordered_map<int,int>numCount;
        for(int num:nums){
            numCount[num]++;
        }
        priority_queue<pair<int,int>> count;
        for(const auto& pair:numCount){
            count.push({pair.second,pair.first});
        }
        
        int len=0;
        while(len<k){
            sol.push_back(count.top().second);
            count.pop();
            ++len;
        }
        return sol;
    }
};