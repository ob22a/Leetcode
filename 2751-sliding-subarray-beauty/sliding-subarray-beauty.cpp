class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        // input is from -50 to 50 so use that to our advantage
        int n=nums.size();
        int freq[101]={};
        vector<int> sol;
        for(int i=0,j=0;i<n;++i){
            freq[nums[i]+50]++;
            if((i-j+1)>k) freq[nums[j++]+50]--;
            
            if((i-j+1)==k){
                int count=0;
                int val=0;
                for(int i=0;i<51;++i){
                    count+=freq[i];
                    if(count>=x){
                        val=i-50;
                        break;
                    }
                }
                sol.emplace_back(val);
            }
        }
        return sol;
    }
};