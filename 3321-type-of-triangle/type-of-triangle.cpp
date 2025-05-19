class Solution {
public:
    string triangleType(vector<int>& nums) {
        int largest=0,second=0,third=0;
        for(int num:nums){
            if(num>largest){
                third=second;
                second=largest;
                largest=num;
            }
            else if(num>second){
                third=second;
                second=num;
            }
            else if(num>third) third=num;
        }
        if(largest>=second+third) return "none";
        if(largest==second && second==third) return "equilateral";
        else if(largest==second || second==third) return "isosceles";
        return "scalene";
    }
};