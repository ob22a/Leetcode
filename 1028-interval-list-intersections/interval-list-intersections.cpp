class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if(secondList.empty() || firstList.empty()) return {};
        vector<vector<int>> sol;
        int i=0,j=0,len1=firstList.size(),len2=secondList.size();
        
        while(i<len1 && j<len2){
            int start1=firstList[i][0],end1=firstList[i][1];
            int start2=secondList[j][0],end2=secondList[j][1];

            int intersectionStart=max(start1,start2);
            int intersectionEnd=min(end1,end2);

            if(intersectionEnd>=intersectionStart)
                sol.push_back({intersectionStart,intersectionEnd});

            if(end1>end2) ++j;
            else ++i;
            
        }
        return sol;
    }
};