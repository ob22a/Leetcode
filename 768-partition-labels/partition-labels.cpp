class Solution {
public:
    vector<int> partitionLabels(string s) {
        int pos[26]={};
        for(int idx=0;idx<s.size();++idx) pos[s[idx]-'a']=idx; 
        // We got the last index of character
        
        vector<int>sol;
        int start=0,end=pos[s[start]-'a'];
        for(int i=0;i<s.size();++i){
            end=max(end,pos[s[i]-'a']);
            if(i==end){
                sol.push_back(end-start+1);
                start=end+1;
            }
        }
        return sol;
    }
};