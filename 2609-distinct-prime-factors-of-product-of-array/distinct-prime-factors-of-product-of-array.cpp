class Solution {
public:
    vector<int> computeSPF(int n){
        vector<int> sol(n+1,0);
        for(int i=2;i<n+1;++i){
            if(sol[i]==0){
                for(int j=i;j<n+1;j+=i){
                    if(sol[j]==0){
                        sol[j]=i;
                    }
                }
            }
        }
        return sol;
    }
    int distinctPrimeFactors(vector<int>& nums) {
        int largest = *max_element(nums.begin(),nums.end());
        vector<int> spf=computeSPF(largest);
        unordered_set<int> seen;
        
        int count=0;
        for(int num:nums){
            while(num!=1){
                if(!seen.count(spf[num])){
                    ++count;
                    seen.insert(spf[num]);
                }
                num/=spf[num];
            }
        }
        return count;
    }
};