class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> preCount(nums.size()+1);
        preCount[0]=1;
        int sum=0,count=0;
        for(int num:nums){
            sum+=(num%2==0)?0:1;
            if(sum-k>=0){
                count+=preCount[sum-k];
            }
            preCount[sum]++;
        }
        return count;
    }
};