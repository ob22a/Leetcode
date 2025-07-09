class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int res = n + 1;

        for(int i=0;i<n;++i) {
            int curOr = 0;
            for (int j = i; j < n; ++j) {
                curOr |= nums[j];
                if (curOr >= k) {
                    res = min(res, j - i + 1);
                    break;
                }
            }
        }
        return (res == n + 1) ? -1 : res;
    }
};