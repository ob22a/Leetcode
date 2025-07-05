class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=0;
        while(j<s.size()){
            while(j<s.size() && s[j++]!=' ');
            int end=(j>=s.size())?s.size():j-1;
            reverse(s.begin()+i,s.begin()+end);
            i=j;
        }
        return s;
    }
};