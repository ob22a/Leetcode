class Solution {
public:
    string RLE(string& s){
        int n = s.size();
        string sol="";
        int count = 1;
        char numChar = s[0];

        for(int i=1;i<n;++i){
            if(s[i]!=numChar){
                sol+=to_string(count);
                sol+=numChar;
                count=1;
                numChar=s[i];
            }
            else ++count;
        }

        if(count!=0){
            sol+=to_string(count);
            sol+=numChar;
        }

        return sol;
    }
    string countAndSay(int n) {
        string cur="1";
        for(int i=1;i<n;++i) cur=RLE(cur);

        return cur;
    }
};