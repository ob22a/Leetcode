class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> allVowels={'a','e','i','o','u','A','E','I','O','U'};
        vector<char> vowels;
        int left=0,right=s.size()-1;
        while(left<right){
            while(left<right && allVowels.count(s[left])==0) ++left;
            while(right>left && allVowels.count(s[right])==0) --right;
            swap(s[left],s[right]);
            ++left;
            --right;
        }
        return s;
    }
};