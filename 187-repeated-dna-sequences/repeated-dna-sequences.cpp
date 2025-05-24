class Solution {
public:
    int convert(char c){
        if(c=='A') return 0b00;
        if(c=='C') return 0b01;
        if(c=='T') return 0b10;
        return 0b11;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        int encode=0;
        unordered_map<int,int> seen;
        vector<string> result;
        for(int i=0;i<s.size();++i){
            encode=((encode<<2) | convert(s[i]))&0xFFFFF;
            if(i>=9){
                if(++seen[encode]==2) result.push_back(s.substr(i-9,10));
            }
        }
        return result;
    }
};