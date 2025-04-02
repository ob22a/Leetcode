class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int i=0,maxLength=0;
        for(int j=0;j<s.size();++j){
            while(seen.find(s[j])!=seen.end()){
                seen.erase(s[i]);
                ++i;
            }
            seen.insert(s[j]);
            maxLength=max(maxLength,j-i+1);
        }
        return maxLength;
    }
};
