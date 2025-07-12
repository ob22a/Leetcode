class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        if(n<t.size()) return "";

        unordered_map<char,int> tHash;
        for(char c:t) tHash[c]++;

        unordered_map<char,int>window;
        int formed=0,target=tHash.size();
        int start=0,minLen=n+1;
        for(int i=0,j=0;j<n;++j){
            window[s[j]]++;
            if(tHash.find(s[j])!=tHash.end() && tHash[s[j]]==window[s[j]]) ++formed;
            while(formed==target){
                if(minLen>j-i+1){
                    start=i;
                    minLen=j-i+1;
                }
                window[s[i]]--;
                if(tHash.find(s[i])!=tHash.end() && tHash[s[i]]>window[s[i]])
                    --formed;
                ++i;
            }   
        }
        return (minLen==n+1)?"":s.substr(start,minLen);
    }
};