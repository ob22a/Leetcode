class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> sol(n);
        int left=0,right=n-1;
        for(int num:nums){
            if(num<pivot) sol[left++]=num;
            else if(num>pivot) sol[right--]=num;
        }
        while(left<=right) sol[left++]=pivot;
        reverse(sol.begin()+right+1,sol.end());
        return sol;
    }
};