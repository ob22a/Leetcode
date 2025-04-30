class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> sol;
        for(int i=0;i<image.size();++i){
            vector<int> row;
            for(int j=image[i].size()-1;j>=0;--j){
                int val=(image[i][j]==1)?0:1;
                row.push_back(val);
            }
            sol.push_back(row);
        }
        return sol;
    }
};