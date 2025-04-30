class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int numbers[101];
        for(int i=nums.size()-1;i>=0;--i){
            if(numbers[nums[i]]!=0){
                int operations=(i+3)/3;
                return operations;

            }
            numbers[nums[i]]++;
        }
        return 0;
    }
};