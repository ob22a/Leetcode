class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>letterCount;
        for(char m:magazine) letterCount[m]++;

        for(char r:ransomNote){
            if(letterCount[r]<=0) return false;
            letterCount[r]--;
        }
        return true;
    }
};