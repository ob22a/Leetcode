class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        if(s2.size()<n) return false;
        array<int,26> c1={},c2={};
        for(char c:s1) c1[c-'a']++;

        for(int i=0;i<s2.size();++i){
            c2[s2[i]-'a']++;
            if(i>=n) c2[s2[i-n]-'a']--;
            if(c1==c2) return true;
        }
        return false;
    }
};