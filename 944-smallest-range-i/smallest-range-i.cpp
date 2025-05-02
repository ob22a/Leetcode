class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int small=INT_MAX,large=INT_MIN;
        for(int num:nums){
            small=min(small,num);
            large=max(large,num);
        }
        int score=(large-small-2*k>0)?large-small-2*k:0;

        return score;
    }
};