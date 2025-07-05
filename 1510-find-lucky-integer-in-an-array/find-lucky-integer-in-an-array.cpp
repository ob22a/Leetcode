class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> counter;
        for(int num:arr) counter[num]++;
        int ans=-1;
        for(const auto& [num,count]:counter){
            if(num==count) ans=max(ans,num);
        }
        return ans;
    }
};