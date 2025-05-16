class Solution {
public:
    int splitNum(int num) {
        vector<int> nums;
        while(num>0){
            nums.push_back(num%10);
            num/=10;
        }
        int num1=0,num2=0;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i+=2){
            num1*=10;
            num1+=nums[i];
            if(i+1<nums.size()){
                num2*=10;
                num2+=nums[i+1];
            }
        }

        return num1+num2;
    }
};