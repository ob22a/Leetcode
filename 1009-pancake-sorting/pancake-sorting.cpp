class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        // Get the largest make it on top and then sort the whole thing to put it in
        // the end
        int n=arr.size();
        vector<int> sol;

        for(int end=n-1;end>0;--end){
            int solIdx=0;
            for(int i=1;i<=end;++i){
                if(arr[i]>arr[solIdx]) solIdx=i;
            }
            if(end==solIdx) continue;

            if(solIdx!=0){
                reverse(arr.begin(),arr.begin()+solIdx+1);
                sol.push_back(solIdx+1);
            }

            reverse(arr.begin(),arr.begin()+end+1);
            sol.push_back(end+1);
        }

        return sol;
    }
};