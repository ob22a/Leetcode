class Solution {
public:
    vector<int> constructRectangle(int area) {
        int l,w,diff=INT_MAX;
        for(int i=1;i<=area;++i){
            int j=area/i;
            if(area%i==0){
                if(abs(i-j)<diff && j<=i){
                    diff=abs(i-j);
                    l=i;
                    w=j;
                }
            }
        }
        return {l,w};
    }
};