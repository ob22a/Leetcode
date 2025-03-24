class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        for(auto it=s.end()-1;it>=s.begin();--it){
            if(*it!=' ') ++count;
            else if(count!=0 && *it==' ') break;
        }
        return count;
    }
};