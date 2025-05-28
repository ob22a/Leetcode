class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        array<int,26> lastAlpha={};
        for(char c:words[0]) lastAlpha[c-'a']++;

        vector<string>sol;
        sol.push_back(words[0]);

        for(int i=1;i<words.size();++i){
            array<int,26> curAlpha={};
            for(char c:words[i]) curAlpha[c-'a']++;

            if(curAlpha!=lastAlpha){
                lastAlpha=curAlpha;
                sol.push_back(words[i]);
            }
        }
        return sol;
    }
};