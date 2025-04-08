class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expectedXOR=0;
        int actualXOR=nums[0];
        int n=nums.size();
        for(int i=1;i<=n;++i) expectedXOR^=i;
        for(int i=1;i<n;++i) actualXOR^=nums[i];

        return expectedXOR^actualXOR;
    }
};