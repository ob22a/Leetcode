class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> stk; //Height,index
        int area = 0; 

        for(int i=0;i<=heights.size();++i){
            int h=(i==heights.size())?0:heights[i];
            int start=i;
            while(!stk.empty() && h<stk.top().first){
                int height=stk.top().first, j=stk.top().second;
                int width=i-j;
                area=max(area,height*width);
                stk.pop();
                start=j;
            }
            stk.push({h,start});
        }
        return area;
    }
};
