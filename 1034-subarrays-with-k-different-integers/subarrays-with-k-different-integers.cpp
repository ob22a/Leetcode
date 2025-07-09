class Solution {
public:
    int atMostK(const vector<int>& nums,int k){
        vector<int> freq(nums.size()+1,0); // Since nums[i] is <= nums.length
        int distinct=0;
        int count=0;
        for(int l=0,r=0;r<nums.size();++r){
            if(freq[nums[r]]==0) ++distinct;
            freq[nums[r]]++;
            while(distinct>k){
                if(--freq[nums[l]]==0) --distinct;
                l++;
            }
            count+=r-l+1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return atMostK(nums,k)-atMostK(nums,k-1);
    }
};