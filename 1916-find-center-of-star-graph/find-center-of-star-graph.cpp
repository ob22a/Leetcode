class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // It is center if it occurs same number of times as edges
        int center=edges[0][0];
        if(center!=edges[1][0] && center!=edges[1][1]) center=edges[0][1];
        return center;
    }
};