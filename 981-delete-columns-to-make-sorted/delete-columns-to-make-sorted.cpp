class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        int len = strs[0].size(), n = strs.size();

        for(int idx=0;idx<len;++idx){
            for(int col=0;col<n-1;++col){
                if(strs[col][idx]>strs[col+1][idx]){
                    ++count;
                    break;
                }
            }
        }

        return count;
    }
};