class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int smallest=5000,largest=-5000; //Based on the test cases
        for(int num:nums){
            smallest=min(smallest,num);
            largest=max(largest,num);
        }
        int shift=-smallest;

        vector<int> index(largest-smallest+2);
        for(int num:nums){
            index[num+shift+1]+=1;
        }
        for(int i=1;i<index.size();++i){
            index[i]+=index[i-1];
        }
        vector<int> sorted(nums.size());
        for(int num:nums){
            sorted[index[num+shift]]=num;
            index[num+shift]++;
        }
        return sorted;
    }
};