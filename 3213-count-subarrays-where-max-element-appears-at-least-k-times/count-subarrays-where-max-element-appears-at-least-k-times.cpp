class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int len=nums.size();
        int maximum=0;
        for(int num:nums) maximum=max(maximum,num);
        
        long long count=0;
        int numOfMax=0;
        
        int i=0;
        for(int j=0;j<len;++j){
            if(nums[j]==maximum) ++numOfMax;
            while(numOfMax>=k){
                if(nums[i]==maximum) --numOfMax;
                ++i;
            }
            count+=i;
        }
        return count;
    }
};