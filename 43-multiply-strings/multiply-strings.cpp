class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";

        vector<int> intermediate(num1.size()+num2.size(),0);

        for(int i=num1.size()-1;i>=0;--i){
            for(int j=num2.size()-1;j>=0;--j){
                int product=(num1[i]-'0')*(num2[j]-'0');
                int sum=product+intermediate[i+j+1];
                intermediate[i+j+1]=sum%10;
                intermediate[i+j]+=sum/10;
            }
        }
        string sol="";
        for(int digit:intermediate){
            if(!(sol.empty() && digit==0)) sol+='0'+digit;
        }

        return sol.empty()?"0":sol;
    }
};