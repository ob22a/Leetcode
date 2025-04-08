class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int actualSum=0;
        for(int num:nums) actualSum+=num;

        int n=nums.size();
        int expectedSum=(n*(n+1)/2);
        
        return expectedSum-actualSum;
    }
};
