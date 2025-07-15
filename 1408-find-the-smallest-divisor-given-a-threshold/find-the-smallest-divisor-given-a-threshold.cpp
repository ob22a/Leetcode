class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=1,r=1;
        for(int num:nums) r=max(r,num);

        while(l<=r){
            int m=l+(r-l)/2;
            int val=0;
            for(int num:nums) val+=(num+m-1)/m; // Ceil divison
            if(val<=threshold) r=m-1;
            else l=m+1;
        }
        return l;
    }
};