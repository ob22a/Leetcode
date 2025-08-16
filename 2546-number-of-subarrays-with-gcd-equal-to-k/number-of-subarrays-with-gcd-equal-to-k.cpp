class Solution {
public:
    int gcd(int a,int b){
        while(b){
            int temp=a;
            a=b;
            b=temp%b;
        }
        return a;
    }
    int subarrayGCD(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;++i){
            int num1=nums[i];
            for(int j=i;j<n;++j){
                num1=gcd(num1,nums[j]);
                if(num1==k) ++count;
                else if(num1<k) break;
            }
        }
        return count;
    }
};