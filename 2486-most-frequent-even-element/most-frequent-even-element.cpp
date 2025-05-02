class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> evenCount;
        for(int num:nums){
            if(num%2==0) evenCount[num]++;
        }
        int mostCount=-1,ans=-1;
        for(const auto& [num,count]:evenCount){
            if(count>mostCount){
                mostCount=count;
                ans=num;
            }
            if(count==mostCount){
                ans=min(ans,num);
            }
        }
        return ans;
    }
};