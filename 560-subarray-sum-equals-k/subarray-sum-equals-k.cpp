class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> compFreq;
        compFreq[0]=1; // To account for subarray of len 1
        int count=0;
        long long preSum=0;
        for(int num:nums){
            preSum+=num;
            if(compFreq.find(preSum-k)!=compFreq.end()){
                count+=compFreq[preSum-k];
            }
            compFreq[preSum]++;
        }
        return count;
    }
};