class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len=nums.size();
        vector<int> squared(len,0);
        int i=0,j=len-1;
        while(i<=j){
            int front=nums[i]*nums[i],back=nums[j]*nums[j];
            if(back>=front){
                squared[j-i]=back;
                --j;
            }
            else{
                squared[j-i]=front;
                ++i;
            }
        }
        return squared;
    }
};