#include<algorithm>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int i=0;
        for(i;i<strs[0].size();++i){
            if(strs.front()[i]!=strs.back()[i]) break;
        }
        return strs[0].substr(0,i);
    }
};
