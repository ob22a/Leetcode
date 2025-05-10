class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name.size()>typed.size()) return false;

        int i=0,j=0;

        while(j<typed.size()){
            if(i<name.size() && name[i]==typed[j]){
                ++i; 
                ++j;
            }
            else if(j>0 && typed[j-1]==typed[j]) ++j;
            else return false;
        }
        return i==name.size();
    }
};