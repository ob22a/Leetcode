class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty()) return {};
        
        int a=nums[0];
        vector<string> ranges;

        for(int i=1;i<=nums.size();++i){
            if(i==nums.size() || nums[i]!=1+nums[i-1]){
                if(a==nums[i-1]) ranges.push_back(to_string(a));
                else ranges.push_back(to_string(a)+"->"+to_string(nums[i-1]));
                if(i<nums.size()) a=nums[i];
            }
        }
        return ranges;
    }
};