class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10) return {};
        unordered_map<string,int> sequence;
        for(int i=0;i<=s.size()-10;++i){
            sequence[s.substr(i,10)]++;
        }
        vector<string> result;
        for(const auto& p:sequence){
            if(p.second>1) result.push_back(p.first);
        }
        return result;
    }
};
