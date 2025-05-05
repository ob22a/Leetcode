class Solution {
public:
    bool digitCount(string num) {
        unordered_map<char,int> counter;
        for(char c:num) ++counter[c];

        for(int i=0;i<num.size();++i){
            char ch=i+'0';
            if(counter[ch]!=(num[i]-'0')) return false;
        }

        return true;
    }
};