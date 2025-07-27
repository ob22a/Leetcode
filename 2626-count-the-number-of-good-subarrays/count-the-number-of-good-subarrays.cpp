class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        long long pairs=0;
        long long sol=0;
        
        for(int i=0,j=0;i<n;++i){
            pairs+=freq[nums[i]];
            freq[nums[i]]++;
            cout<<pairs;
            while(pairs>=k){
                sol+=(n-i);
                pairs+=(1-freq[nums[j]]);
                freq[nums[j++]]--;
            }
        }
        return sol;
    }
};