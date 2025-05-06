class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> counter;
        for(int num:nums) counter[num]++;
        
        vector<pair<int,int>> numCount;
        for(const auto&[n,count]:counter) numCount.push_back({n,count});

        sort(numCount.begin(),numCount.end(),[](pair<int,int>&a,pair<int,int>&b){
            if(a.second==b.second) return a.first>b.first;
            return a.second<b.second;
        });
        int j=0;
        for(int i=0;i<nums.size();++j){
            while(numCount[j].second>0){
                nums[i]=numCount[j].first;
                ++i;
                numCount[j].second--;
            }
        }

        return nums;
    }
};