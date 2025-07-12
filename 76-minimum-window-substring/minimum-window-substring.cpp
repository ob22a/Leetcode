class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        if(n<t.size()) return "";

        vector<int> tHash(256,0);
        int target=0;
        for(char c:t){
            if(tHash[c]==0) ++target;
            tHash[c]++;
        }

        vector<int> window(256,0);
        int formed=0;
        int start=0,minLen=n+1;
        for(int i=0,j=0;j<n;++j){
            window[s[j]]++;
            if(tHash[s[j]]!=0 && tHash[s[j]]==window[s[j]]) ++formed;
            while(formed==target){
                if(minLen>j-i+1){
                    start=i;
                    minLen=j-i+1;
                }
                window[s[i]]--;
                if(tHash[s[i]]!=0 && tHash[s[i]]>window[s[i]])
                    --formed;
                ++i;
            }   
        }
        return (minLen==n+1)?"":s.substr(start,minLen);
    }
};