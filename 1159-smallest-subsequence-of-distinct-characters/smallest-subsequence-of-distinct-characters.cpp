class Solution {
public:
    string smallestSubsequence(string s) {
        string sol;
        unordered_map<char,int> freq;
        for(char c:s){
            freq[c]++;
        }
        unordered_set<char> seen;
        for(char c:s){
            freq[c]--;
            if(!seen.count(c)){
                while(!sol.empty() && sol.back()>c && freq[sol.back()]>0){
                    seen.erase(sol.back());
                    sol.pop_back();
                }
                
                sol.push_back(c);
                seen.insert(c);
            }  
        }
        return sol;
    }
};