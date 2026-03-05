class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        left = 0
        right=n-1
        area=0

        while left<right:
            h=min(height[left],height[right])
            w=right-left
            area=max(area,h*w)

            if height[left]>height[right]:
                right-=1
            else:
                left+=1
        
        return area