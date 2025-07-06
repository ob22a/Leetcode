class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long sol=0;
        int lastMax=-1,lastMin=-1,lastValid=-1;
        for(int i=0;i<nums.size();++i){
            if(nums[i]<minK || nums[i]>maxK) lastValid=i;
            if(nums[i]==minK) lastMin=i;
            if(nums[i]==maxK) lastMax=i;

            int validStart=min(lastMin,lastMax);
            if(validStart>lastValid) sol+=(validStart-lastValid);
        }
        return sol;
    }
};