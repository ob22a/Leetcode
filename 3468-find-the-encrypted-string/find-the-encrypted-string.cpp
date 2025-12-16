class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n=s.size();

        string encrypted="";
        for(int idx=0;idx<n;++idx) encrypted+=s[(idx+k)%n];

        return encrypted;
    }
};