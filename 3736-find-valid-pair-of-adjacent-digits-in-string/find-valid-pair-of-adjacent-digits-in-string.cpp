class Solution {
public:
    string findValidPair(string s) {
        unordered_map<int,int> count;
        string sol="";
        for(char c:s){
            int num=c-'0';
            count[num]++;
        }
        for(int i=0;i<s.size()-1;++i){
            int num=s[i]-'0';
            int nextNum=s[i+1]-'0';
            if(num!=nextNum && num==count[num]){
                if(nextNum==count[nextNum]){
                    sol+=s[i];
                    sol+=s[i+1];
                    break;
                }
                ++i;
            }
        }
        return sol;
    }
};