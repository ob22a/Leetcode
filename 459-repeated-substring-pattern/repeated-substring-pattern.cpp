class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        string temp=s+s;
        temp=temp.substr(1,temp.size()-2);
        return temp.find(s) != -1;
    }
};