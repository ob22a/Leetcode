class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int top=0,bottom=n-1;
        while(top<=bottom){
            int mid=top+(bottom-top)/2;
            int maxCol=((max_element(mat[mid].begin(),mat[mid].end()))-mat[mid].begin());
            int tp=(mid>0)?mat[mid-1][maxCol]:-1;
            int bt=(mid<n-1)?mat[mid+1][maxCol]:-1;
            int cur=mat[mid][maxCol];

            if(cur>tp && cur>bt) return {mid,maxCol};
            else if(cur<tp) bottom=mid-1;
            else top=mid+1;
        }
        return {};
    }
};