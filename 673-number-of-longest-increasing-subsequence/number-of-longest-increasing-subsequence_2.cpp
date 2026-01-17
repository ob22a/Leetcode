class Solution {
public:
    pair<int,int> solve(vector<int>& nums, int prev, int idx){
        if(idx==nums.size()) return {0,1};
        pair<int,int> skip = solve(nums,prev,idx+1);
        pair<int,int> take = {0,0};

        if(prev==-1 || nums[prev]<nums[idx]){
            take = solve(nums,idx,idx+1);
            take.first++;
        }

        if(skip.first>take.first) return skip;
        else if(take.first>skip.first) return take;
        return {take.first,take.second+skip.second};
    }
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        // Tabulate the rec solution
        vector<int> count(n+1,1); 
        vector<int> length(n+1,0); 

        for(int idx=n-1;idx>=0;--idx){
            for(int prev=0;prev<=idx;++prev){ // move -1 to be 0 and so on
                int skipCnt = count[prev]; 
                int skipLen = length[prev];

                int takeCnt = 0, takeLen = 0;

                if(prev==0 || nums[idx]>nums[prev-1]){
                    takeCnt = count[idx+1] ;
                    takeLen = length[idx+1]+1;
                }

                length[prev] = max(skipLen,takeLen) ;
                count[prev] = (skipLen>takeLen) ? skipCnt : (takeLen>skipLen) ? takeCnt : skipCnt + takeCnt;
            }
        }

        return count[0];
    }
};
