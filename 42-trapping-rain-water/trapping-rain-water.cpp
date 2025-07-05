class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,leftMax=0,rightMax=0,sol=0,right=height.size()-1;
        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>leftMax) leftMax=height[left];
                else sol+=leftMax-height[left];
                ++left;
            }
            else{
                if(height[right]>rightMax) rightMax=height[right];
                else sol+=rightMax-height[right];
                --right;
            }
        }
        return sol;
    }
};