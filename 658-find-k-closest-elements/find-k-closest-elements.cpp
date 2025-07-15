class Solution {
public:
    int bs(const vector<int>& arr,const int x){
        int l=0,r=arr.size();
        while(l<r){
            int mid=l+(r-l)/2;
            if(arr[mid]<x) l=mid+1;
            else r=mid;
        }
        return l; // First Occurence if the element did exist 
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx=bs(arr,x);
        int i=idx-1,j=idx;
        for(int counter=0;counter<k;++counter){
            if(i>=0 && j<arr.size()){
                int leftDiff=abs(arr[i]-x);
                int rightDiff=abs(arr[j]-x); 
                if(leftDiff>rightDiff) ++j;
                else --i;
            }
            else if(i>=0) --i;
            else if(j<arr.size()) ++j;
        }
        return vector<int>(arr.begin()+i+1,arr.begin()+j); // End is exclusive
    }
};