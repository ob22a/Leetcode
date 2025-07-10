class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int> delta(n+1,0);
        for(const vector<int>& shift:shifts){
            int start=shift[0],end=shift[1],direction=shift[2];
            int change=(direction==1)?1:-1;
            delta[start]+=change;
            if(end+1<n) delta[end+1]-=change;
        }

        int cur=0;
        for(int i=0;i<n;++i){
            cur+=delta[i];
            int num=(s[i]-'a' + cur) % 26;
            if (num < 0) num += 26;
            s[i]='a'+num;
        }

        return s;
    }
};