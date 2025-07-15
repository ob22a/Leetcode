class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int l=0,r=(n*m)-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int midRow = mid/m;
            int midCol=mid%m;
            if(matrix[midRow][midCol]==target) return true;
            else if(matrix[midRow][midCol]>target) r=mid-1;
            else l=mid+1;
        }
        return false;
    }
};