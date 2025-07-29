class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left=0,right=n-1,top=0,bottom=n-1;
        int counter=1;
        vector<vector<int>>sol(n,vector<int>(n,0));
        while(left<=right && top<=bottom){
            for(int i=left;i<=right;++i) sol[top][i]=counter++;
            top++;
            for(int i=top;i<=bottom;++i) sol[i][right]=counter++;
            right--;
            if(left<=right){
                for(int i=right;i>=left;--i) sol[bottom][i]=counter++;
                bottom--;
            }
            if(top<=bottom){
                for(int i=bottom;i>=top;--i) sol[i][left]=counter++;
                left++;
            }
        }
        return sol;
    }
};