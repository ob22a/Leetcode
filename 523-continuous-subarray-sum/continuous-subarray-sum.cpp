class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        /*
        a b c d 
        a mod k
        a+b mod k = (a mod k + b mod k) mod k
        a+b+c mod k = (a mod k + b mod k + c mod k) mod k = (a mod k + (b+c) mod k) mod k
        So if there is repeatition we found the answer since some sum equals 0
        */

        int n=nums.size();
        unordered_map<int,int> seenIdx;
        seenIdx[0]=-1;
        long long sum=0;
        for(int i=0;i<n;++i){
            sum+=nums[i];
            int mod=sum%k;
            if(seenIdx.find(mod)!=seenIdx.end()){
                if(i-seenIdx[mod]>=2) return true;
            }
            else seenIdx[mod]=i;
        }
        return false;
    }
};