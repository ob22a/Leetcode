class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int arr[101]={};
        for(int num:nums) arr[num]++;
        int sum=0;
        for(int i=0;i<101;++i){
            if(arr[i]==1) sum+=i;
        }
        return sum;
    }
};