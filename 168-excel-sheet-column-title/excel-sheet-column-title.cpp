class Solution {
public:
    string convertToTitle(int columnNumber) {
        string sol="";
        while(columnNumber>0){
            char letter='A'+(columnNumber-1)%26;
            sol.insert(0,1,letter);
            columnNumber=(columnNumber-1)/26;
        }
        return sol;
    }
};