class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1,j=num2.size()-1;
        string reversedSum="",sum="";
        int carry=0;
        while(i>=0 || j>=0 || carry!=0){
            int leftSum=carry;
            if(i>=0){
                leftSum+=num1[i]-'0';
                --i;
            }
            if(j>=0){
                leftSum+=num2[j]-'0';
                --j;
            }
            reversedSum.push_back(leftSum%10+'0');
            carry=leftSum/10;
        }
        for(int i=reversedSum.size()-1;i>=0;--i){
            sum.push_back(reversedSum[i]);
        }
        return sum;
    }
};