class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> sol;

        sort(intervals.begin(),intervals.end());

        vector<int> uniqueInterval=intervals[0];

        int len=intervals.size();

        for(int i=1;i<len;++i){
            int start=intervals[i][0],end=intervals[i][1];
            if(uniqueInterval[1]>=start){
                uniqueInterval[1]=max(end,uniqueInterval[1]);
            }
            else{
                sol.push_back(uniqueInterval);
                uniqueInterval=intervals[i];
            }
        }
        sol.push_back(uniqueInterval);
        return sol;
    }
};