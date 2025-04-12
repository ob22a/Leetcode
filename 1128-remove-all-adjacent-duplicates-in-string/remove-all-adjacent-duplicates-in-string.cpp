class Solution {
public:
    string removeDuplicates(string s) {
        string sol="";
        for(char letter:s){
            if(!sol.empty() && (sol.back()==letter)) sol.pop_back();
            else sol.push_back(letter);
        }
        return sol;
    }
};