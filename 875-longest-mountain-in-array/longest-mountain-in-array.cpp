class Solution {
public:
    // We need to track those who increase strictly
    int f(vector<int>& arr,int idx){
        if(idx==0 || arr[idx-1]>=arr[idx]) return 0;
        return 1 + f(arr,idx-1);
    }
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        if(n<3) return 0;

        vector<int> up(n,0);
        vector<int> down(n,0);
        
        for(int i=0;i<n;++i){
            if(i==0 || arr[i-1]>=arr[i]) continue;
            up[i]=1+up[i-1];
        }

        for(int i=n-1;i>=0;--i){
            if(i==n-1 || arr[i+1]>=arr[i]) continue;
            down[i]= 1+down[i+1];
        }

        int sol=0;
        
        for(int i=0;i<n;++i){
            if(up[i]>0 && down[i]>0 ) sol=max(sol,up[i]+down[i]+1);
        }

        return sol;
    }
};