class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negCount=0;
        for(negCount;negCount<nums.size();++negCount){
            if(nums[negCount]>=0) break;
        }
        int posCount=nums.size()-negCount;
        for(int i=negCount;i<nums.size();++i){
            if(nums[i]==0) --posCount;
            else break;
        }
        int result=max(negCount,posCount);
        return result;
    }
};