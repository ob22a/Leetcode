class Solution {
public:
    int lcm(int a,int b){
        long long product=1ll*a*b;
        while(b){
            int temp=a;
            a=b;
            b=temp%b;
        }
        return product/a;
    }
    int subarrayLCM(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;++i){
            int val=1;
            for(int j=i;j<n;++j){
                val=lcm(val,nums[j]);
                if(val==k) ++count;
                else if(val>k) break;
            }
        }
        return count;
    }
};