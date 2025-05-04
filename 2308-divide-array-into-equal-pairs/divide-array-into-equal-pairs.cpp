class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int freq[501]={};
        for(int num:nums) freq[num]++;
        for(int f:freq){
            if(f%2) return false;
        }
        return true;
    }
};