class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> comp={{')','('},{'}','{'},{']','['}};
        vector<char>stack;
        for(char sym:s){
            if(comp.count(sym)){
                if(stack.empty()) return false;
                else{
                    if(stack.back()==comp[sym]){
                        stack.pop_back();
                    }
                    else return false;
                }
            }
            else stack.push_back(sym);
        }
        return(stack.empty());
    }
};