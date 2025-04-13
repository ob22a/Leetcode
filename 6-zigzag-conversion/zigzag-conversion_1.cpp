class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        string zigzag="";
        for(int i=0;i<numRows;++i){
            int j=i;
            while(j<s.size()){
                if(j-(2*i)>0 && j-(2*i)!=j && j-(2*i)!=j-2*(numRows-1)){
                    zigzag+=s[j-(2*i)];
                    zigzag+=s[j];
                }
                else zigzag+=s[j];
                
                if(j+2*(numRows-1)>=s.size() && j+2*(numRows-1)-(2*i)<s.size() && j+2*(numRows-1)-(2*i)!=j)
                    zigzag+=s[j+2*(numRows-1)-(2*i)];
                
                j+=2*(numRows-1);
            }
        }
        return zigzag;
    }
};
