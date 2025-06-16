class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff=-1,min=INT_MAX;
        for(int num:nums){
            if(num!=min) maxDiff=max(maxDiff,num-min);
            if(num<min) min=num;
        }
        return maxDiff;
    }
};