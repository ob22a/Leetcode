class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        bool flag = false;
        int n=nums.size();

        for(int i=0;i<n;++i){
            unordered_set<int> seen;
            int idx = i;
            int next = ((idx + nums[idx]) % n + n) % n;
            bool isForward = nums[idx]>0;
            while(idx!=next){
                if(nums[next]>0 != isForward) break;
                if(seen.find(idx)!=seen.end()){
                    flag=true;
                    break;
                }
                seen.insert(idx);
                idx=next;
                next=((idx + nums[idx]) % n + n) % n;
            }
        }

        return flag;
    }
};