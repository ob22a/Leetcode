class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> pos;
        for(int idx=0;idx<s.size();++idx) pos[s[idx]]=idx; 
        // We got the last index of character
        
        vector<int>sol;
        int start=0,end=pos[s[start]];
        for(int i=0;i<s.size();++i){
            end=max(end,pos[s[i]]);
            if(i==end){
                sol.push_back(end-start+1);
                start=end+1;
            }
        }
        return sol;
    }
};