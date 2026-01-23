class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> sol;

        for(int num:nums){
            if (num == 2) {
                sol.push_back(-1);
                continue;
            }

            int value = -1;
            for (int bit = 1; bit < 32; ++bit) {
                if (((num >> bit) & 1) == 0) {
                    value = num ^ (1 << (bit - 1));
                    break;
                }
            }
            sol.push_back(value);
        }  

        return sol;
    }
};