class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),
            [](const vector<int>& a,const vector<int>& b){
                return a[1]>b[1];
        });
        int sol=0;

        for(const vector<int>& vec:boxTypes){
            int box=vec[0],unit=vec[1];
            if(truckSize<=0) break;
            int boxes= min(truckSize,box);
            truckSize-=boxes;
            sol+=(boxes*unit);
        }
        return sol;
    }
};