class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        long long total=accumulate(nums.begin(),nums.end(),0ll);
        long long sum=0;
        int sol=0,avg=INT_MAX;
        for(int i=0;i<n;++i){
            sum+=nums[i];
            int leftAvg=sum/(i+1),rightAvg=(i==n-1)?0:(total-sum)/(n-i-1);
            if(avg>abs(leftAvg-rightAvg)){
                sol=i;
                avg=abs(leftAvg-rightAvg);
            }
        }
        return sol;
    }
};