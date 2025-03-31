class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char map1[128]={};
        char map2[128]={};
        for(int i=0;i<s.size();++i){//Since s.size()==t.size()
            if(map1[s[i]]==0 && map2[t[i]]==0){
                map1[s[i]]=t[i];
                map2[t[i]]=s[i];
            }
            else if (map1[s[i]]!=t[i] || map2[t[i]]!=s[i]) return false;
        }
        return true;
    }
};