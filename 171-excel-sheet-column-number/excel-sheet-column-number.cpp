class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sol=0;
        for(char letter:columnTitle){
            sol=sol*26+(letter-'A'+1);
        }
        return sol;
    }
};