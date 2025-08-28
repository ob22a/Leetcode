class Solution {
public:
    void nextPermutation(string& s){
        int i=s.size()-2;
        while(i>=0 && s[i]>s[i+1]) --i;

        if(i>=0){
            int j=s.size()-1;
            while(j>=0 && s[i]>s[j]) --j;
            swap(s[i],s[j]);
        }
        reverse(s.begin()+i+1,s.end());
    }
    string getPermutation(int n, int k) {
        string sol="";
        for(int i=1;i<=n;++i) sol+=char(i+'0');
        for(int i=1;i<k;++i) nextPermutation(sol);

        return sol;
    }
};