class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w=sqrt(area); //Leetcode question description is wrong W>=L
        while(area%w!=0) --w;
        return {area/w,w};
    }
};