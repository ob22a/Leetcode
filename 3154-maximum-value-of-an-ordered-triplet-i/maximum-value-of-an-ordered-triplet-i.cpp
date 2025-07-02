class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long sol=0,maxElement=0,maxDiff=0;
        for(long long num:nums){
            sol=max(sol,num*maxDiff);
            maxDiff = max(maxDiff,maxElement-num);
            maxElement = max(maxElement,num);
        }
        return sol;
    }
};