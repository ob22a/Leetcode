class Solution {
public:
    string toHex(int num) {
        if(num==0) return"0";

        string hexa="";
        string values="0123456789abcdef";

        unsigned int n=num;
        /*To handle negative numbers since it can hold up to 2^32-1(this is equal to -1 in int ) and goes down from here. This is also how it is stored in int
        */
        while(n!=0){
            hexa=values[n%16]+hexa;
            n/=16;
        }
        
        return hexa;
    }
};