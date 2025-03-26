#include<algorithm>
class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        int i=a.size()-1;
        int j=b.size()-1;
        string sol="";
        while(i>=0 or j>=0 or carry){
            if(i>=0){
                carry+=(int)(a[i]-'0');
                --i;
            }
            if(j>=0){
                carry+=(int)(b[j]-'0');
                --j;
            }
            sol.append(to_string(carry%2));
            carry/=2;
        }
        reverse(sol.begin(),sol.end());
        return sol;
    }
};