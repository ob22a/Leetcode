class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> compFreq;
        compFreq[0]=-1;
        int sum=0;
        int len=0;
        for(int i=0;i<nums.size();++i){
            sum+=(nums[i]==0)?-1:1;
            if(compFreq.find(sum)!=compFreq.end()){
                len=max(len,i-compFreq[sum]);
            }
            else compFreq[sum]=i;
        }
        return len;
    }
};