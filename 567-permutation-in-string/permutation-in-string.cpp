class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        if(s2.size()<n) return false;
        array<int,26> c1={};
        for(char c:s1) c1[c-'a']++;

        for(int i=0;i<s2.size();++i){
            if(c1[s2[i]-'a']==0) continue;
            array<int,26> curr={};
            for(int j=i;j<i+n && j<s2.size();++j){
                if(c1[s2[j]-'a']==0) break;
                curr[s2[j]-'a']++;
            }
            if(c1==curr) return true;
        }
        return false;   
    }
};