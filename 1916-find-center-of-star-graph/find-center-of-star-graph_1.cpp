class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // It is center if it occurs same number of times as edges
        unordered_map<int,int> counter;
        for(int i=0;i<edges.size();++i){
            counter[edges[i][0]]++; counter[edges[i][1]]++;
        }
        for(const auto& p:counter){
            if(p.second==edges.size()) return p.first;
        }
        return -1;
    }
};
