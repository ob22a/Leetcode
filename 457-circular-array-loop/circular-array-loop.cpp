class Solution {
public:
    int nextIndex(int i,vector<int>& nums){
        int n=nums.size();
        bool isForward=(nums[i]>0);
        int next = ((i+nums[i])%n + n)%n;

        if(next==i || ((nums[next]>0) != isForward)) return -1; 
        return next;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;++i){
            if(nums[i]==0) continue;

            int slow=i, fast=i;
            while(true){
                slow = nextIndex(slow,nums);
                fast = nextIndex(fast,nums);
                if(fast!=-1) fast=nextIndex(fast,nums);

                if(slow==-1 || fast==-1){
                    int cur=0;
                    while(cur!=-1 && nums[cur]!=0){
                        int next=nextIndex(cur,nums);
                        nums[cur]=0;
                        cur=next;
                    }
                    break;
                }
                if(slow==fast){
                    int next=nextIndex(slow,nums);
                    if(next!=-1 && next!=slow) return true;

                    int cur = i;
                    while(cur!=-1 && nums[cur]!=0){
                        int next = nextIndex(cur,nums);
                        nums[next]=0;
                        cur=next;
                    }
                    break;
                }
            }
        }

        return false;
    }
};