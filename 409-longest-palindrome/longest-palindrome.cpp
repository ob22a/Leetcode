class Solution {
public:
    int longestPalindrome(string s) {
        /* Even characters each contribute fully
            Odd characters each contribute n-1 and one of it adds additional 1(center)
        */
        unordered_map<char,int> counter;
        for(char c:s){
            counter[c]++;
        }
        int length=0;
        bool hasOdd=false;

        for(const auto&[letter,count]:counter){
            if(count%2!=0){
                length+=count-1;
                hasOdd=true;
            }
            else length+=count;
        }
        if(hasOdd) ++length;

        return length;
    }
};