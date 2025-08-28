class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num:nums) freq[num]++;

        int maxFreq=0;
        int count=0;
        for(const auto& p:freq){
            if(p.second>maxFreq){
                maxFreq=p.second;
                count=maxFreq;
            }
            else if(p.second==maxFreq) count+=maxFreq;
        }
        return count;
    }
};