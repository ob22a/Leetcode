class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            If we finished robbing we are either at last house or the house before that
            so we can either take 0th house or not and choose max
        */

        int n=nums.size();
        if(n==1) return nums[0];
        
        auto robHouse = [&](int l,int r)->int{
            int prev1=0,prev2=0;
            for(int i=l;i<=r;++i){
                int take = prev2 + nums[i];
                int notTake = prev1;
                int cur = max(take,notTake);
                prev2=prev1;
                prev1=cur;
            }
            return prev1;
        };

        return max(robHouse(0,n-2),robHouse(1,n-1));
    }
};