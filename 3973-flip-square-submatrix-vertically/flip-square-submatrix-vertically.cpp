class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n=grid.size();
        for(int top=x,bottom=x+k-1;top<bottom;++top,--bottom){
            for(int col=y;col<(y+k);++col){
                int temp=grid[top][col];
                grid[top][col]=grid[bottom][col];
                grid[bottom][col]=temp;
            }
        }
        return grid;
    }
};