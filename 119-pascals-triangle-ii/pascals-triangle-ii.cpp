class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascal={{1}};
        for(int i=2;i<rowIndex+2;++i){
            vector<int> row(i,1);
            for(int j=1;j<i-1;++j){
                row[j]=pascal.back()[j]+pascal.back()[j-1];
            }
            pascal.push_back(row);
        }
        return pascal[rowIndex];
    }
};