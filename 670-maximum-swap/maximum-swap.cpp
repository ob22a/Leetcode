class Solution {
public:
    int vecToNum(vector<int> nums){
        int num=0;
        for(int n:nums) num=num*10+n;
        return num;
    }
    int maximumSwap(int num) {
        vector<int>digits;
        int temp=num;
        if(num==0) digits.push_back(0);
        else{
            while(temp>0){
                digits.push_back(temp%10);
                temp/=10;
            }
        }
        reverse(digits.begin(),digits.end());

        int sol=num;
        bool isSwapped=false;
        int maximum=0;
        for(int i=0;i<digits.size()-1;++i){
            for(int j=digits.size()-1;j>i;--j){
                if(digits[j]>digits[i] && digits[j]>maximum){
                    maximum=digits[j];
                    vector<int> tempVec=digits;
                    swap(tempVec[i],tempVec[j]);
                    sol=vecToNum(tempVec);
                    isSwapped=true;
                }
            }
            if(isSwapped) break;
        }
        return sol;
    }
};