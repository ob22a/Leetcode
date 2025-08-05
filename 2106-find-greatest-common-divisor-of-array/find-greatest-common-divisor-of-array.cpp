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
    int findGCD(vector<int>& nums) {
        int small=*min_element(nums.begin(),nums.end());
        int large=*max_element(nums.begin(),nums.end());
        return gcd(large,small);
    }
};