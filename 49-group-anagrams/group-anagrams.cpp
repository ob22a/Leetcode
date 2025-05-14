class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int,26>,vector<string>> anagrams;

        for(string word:strs){
            array<int,26> count={};
            for(char c:word){
                ++count[c-'a'];
            }
            anagrams[count].push_back(word);
        }

        vector<vector<string>> sol;

        for(const auto& [counter,word]:anagrams){
            sol.push_back(word);
        }

        return sol;
    }
};