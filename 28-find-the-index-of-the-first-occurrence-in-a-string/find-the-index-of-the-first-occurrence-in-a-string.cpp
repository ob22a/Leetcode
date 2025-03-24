class Solution {
public:
    int strStr(string haystack, string needle) {
        int n= needle.size();
        for(int j=0;j<haystack.size();++j){
            if(haystack.at(j)==needle.at(0)){
                if(haystack.substr(j,n)==needle) return j;
            }
        }
        return -1;
    }
};