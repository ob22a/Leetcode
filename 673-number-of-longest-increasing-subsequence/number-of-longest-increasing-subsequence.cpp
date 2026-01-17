class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> cnt(n,1), len(n,1);
        for(int end=0;end<n;++end){
            for(int prev=0;prev<end;++prev){
                if(nums[prev]<nums[end]){
                    if(len[prev]+1==len[end]) cnt[end]+=cnt[prev];
                    else if(len[prev]+1>len[end]){
                        len[end]=len[prev]+1;
                        cnt[end]=cnt[prev];
                    }
                }
            }
        }

        int maxi = *max_element(len.begin(),len.end());
        int sol=0;
        for(int i=0;i<n;++i){
            if(len[i]==maxi) sol+=cnt[i];
        }

        return sol;
    }
};