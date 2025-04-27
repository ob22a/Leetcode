class Solution {
public:
    bool isEqual(string s){
        int l=0,r=0;
        for(int i=0;i<s.size()/2;++i){
            l+=s[i]-'0';
        }
        for(int i=s.size()/2;i<s.size();++i){
            r+=s[i]-'0';
        }
        return l==r;
    }
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;++i){
            string sNum=to_string(i);
            if(sNum.size()%2==0){
                if(isEqual(sNum)) ++count;
            }
        }
        return count;
    }
};