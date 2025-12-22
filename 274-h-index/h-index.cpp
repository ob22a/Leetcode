class Solution {
public:
    bool isValid(vector<int>& c, int n){
        int cnt = 0;
        for(int num:c){
            if(num>=n) ++cnt;
        }
        return cnt>=n;
    }
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        // BS on answer space the answer ranges from [largest num - size of citations]
        // for each num we isValid(num)
        // since we want the largest l=mid+1 r = mid l!=r
        int maxVal = *max_element(citations.begin(),citations.end());
        int minVal = *min_element(citations.begin(),citations.end());
        int l = min(n,minVal);
        int r = max(n,maxVal);

        while(l<r){
            int m = l+(r-l)/2+1; // to ensure it rounds up
            if(isValid(citations,m)) l=m;
            else r=m-1;
        }

        return r;
    }
};