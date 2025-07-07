class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        if(k==0) return vector<int>(n);
        if(n==1) return code;

        vector<int> preSum(n);
        int left=0;
        int len=0,sum=0;

        for(int right=1;left<n;++right){
            int idx=right%n;
            sum+=code[idx];
            ++len;
            if(len==abs(k)){
                preSum[left]=sum;
                int first = (left+1)%n;
                ++left;
                sum-=code[first];
                --len;
            }
        }

        // Rotate the array incase k is negative
        if(k<0){
            k*=-1;
            reverse(preSum.begin(),preSum.end());
            reverse(preSum.begin(),preSum.begin()+k+1);
            reverse(preSum.begin()+k+1,preSum.end());
        }
        return preSum;
    }
};