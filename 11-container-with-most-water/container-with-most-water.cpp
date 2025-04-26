class Solution {
public:
    int maxArea(vector<int>& height) {
        int maximum=0;
        int i=0,j=height.size()-1;
        while(i<j){
            int h=min(height[i],height[j]);
            int area=h*(j-i);
            if(height[i]>=height[j]) --j;
            else ++i;
            maximum=max(maximum,area);
        }
        return maximum;
    }
};