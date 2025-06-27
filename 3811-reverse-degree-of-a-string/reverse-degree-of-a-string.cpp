class Solution {
public:
    int reverseDegree(string s) {
        int sol=0;
        for(int i=0;i<s.size();++i) sol+=((abs(s[i]-'z')+1)*(i+1));
        return sol;
    }
};
