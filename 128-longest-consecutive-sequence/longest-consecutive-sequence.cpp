class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int n:nums) set.insert(n);
        
        int longest=0,length=0;
        for(int num:set){
            if(!set.count(num-1)){
                length=0;
                while(set.count(num+length)) ++length;
                longest=max(longest,length);
            }
        }
        return longest;
    }
};