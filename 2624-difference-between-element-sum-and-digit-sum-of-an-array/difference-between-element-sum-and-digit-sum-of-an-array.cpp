class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elementSum = 0;
        int digitSum = 0;

        for(int num:nums){
            elementSum+=num;
            while(num){
                digitSum+=num%10;
                num/=10;
            }
        }

        return abs(digitSum-elementSum);
    }
};