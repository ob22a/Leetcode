class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int& num:nums){
            if(num%2==0) num=0;
            else num=1;
        }
        unordered_map<int,int> preCount;
        preCount[0]=1;
        int sum=0,count=0;
        for(int num:nums){
            sum+=num;
            if(preCount.find(sum-k)!=preCount.end()){
                count+=preCount[sum-k];
            }
            preCount[sum]++;
        }
        return count;
    }
};