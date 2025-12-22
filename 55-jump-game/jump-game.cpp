class Solution {
public:
    bool canJump(vector<int>& nums) {
        // can I reach an idx if that index is not the furthest i can reach return false

        int n = nums.size();
        int far = 0;

        for(int i=0;i<n;++i){
            if(i>far) return false;
            far = max(far,i+nums[i]);
        }

        return true;
    }
};