class Solution {
public:
    string longestPalindrome(string s) {
        string longest="";

        for(int mid=0;mid<s.size();++mid){
            auto [s1,l1]=helper(s,mid,mid+1);
            auto [s2,l2]=helper(s,mid-1,mid+1);
            if(l1>longest.size()) longest=s.substr(s1,l1);
            if(l2>longest.size()) longest=s.substr(s2,l2);
        }

        return longest;
    }
    tuple<int,int> helper(const string& s,int left, int right){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            --left;
            ++right;
        }
        return {left+1,right-left-1};
    }
};