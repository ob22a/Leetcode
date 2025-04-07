class Solution {
public:
    bool isAnagram(string s, string t) {
        int counter[26]={};
        int length=0;

        for(char c:s){
            counter[c-'a']++;
            ++length;
        }

        for(char c:t){
            if(counter[c-'a']<=0) return false;
            else{
                --counter[c-'a'];
                --length;
            }
        }
        
        return length==0;
    }
};