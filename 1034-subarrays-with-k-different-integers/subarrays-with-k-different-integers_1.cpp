class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int count1=0;
        unordered_map<int,int> countK; //At most K times
        for(int l=0,r=0;r<nums.size();++r){
            countK[nums[r]]++;
            while(countK.size()>k){
                if(--countK[nums[l]]==0) countK.erase(nums[l]);
                ++l;
            }
            count1+=r-l+1;
        }

        int count2=0;
        unordered_map<int,int> countK2; // At most k-1 times
        for(int l=0,r=0;r<nums.size();++r){
            countK2[nums[r]]++;
            while(countK2.size()>k-1){
                if(--countK2[nums[l]]==0) countK2.erase(nums[l]);
                ++l;
            }
            count2+=r-l+1;
        }
        
        return count1-count2; // At most k times - at most k-1 times 
    }
};
