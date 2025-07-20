class Solution {
public:
    bool isValid(const vector<int>& nums,const vector<long long>& sum,long long limit){
        for(int i=0;i<nums.size();++i){
            if(sum[i+1]>limit*(i+1)) return false;
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        vector<long long> preSum(n+1,0);
        for(int i=0;i<n;++i) preSum[i+1]=preSum[i]+nums[i];
        int l=0,r=(*max_element(nums.begin(),nums.end()));
        while(l<r){
            long long m=l+(r-l)/2;
            if(isValid(nums,preSum,m)) r=m;
            else l=m+1;
        }
        return l;
    }
};
