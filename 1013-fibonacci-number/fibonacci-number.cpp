class Solution {
public:
    vector<vector<int>> matrixProduct(vector<vector<int>>a,vector<vector<int>>b){
        vector<vector<int>> c(2,vector<int>(2));
        c[0][0]=(a[0][0]*b[0][0])+(a[0][1]*b[1][0]);
        c[0][1]=(a[0][0]*b[0][1])+(a[0][1]*b[1][1]);
        c[1][0]=(a[1][0]*b[0][0])+(a[1][1]*b[1][0]);
        c[1][1]=(a[1][0]*b[0][1])+(a[1][1]*b[1][1]);
        
        return c;
    }
    vector<vector<int>> matrixPower(vector<vector<int>>a,int num){
        if(num==0) return {{1,0},{0,1}};

        vector<vector<int>> middle=matrixPower(a,num/2);
        
        if(num%2==0) return matrixProduct(middle,middle);
        else return matrixProduct(a,matrixProduct(middle,middle));
    }
    int fib(int n) {
       vector<vector<int>> M(2,vector<int>(2));
       M[0][0]=1;
       M[0][1]=1;
       M[1][0]=1;
       M[1][1]=0;

       vector<vector<int>> sol=matrixPower(M,n);

       return sol[0][1];
    }
};