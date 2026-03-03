class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        stk = [] #idx height
        area = 0

        for i in range(n+1):
            start = i
            h = heights[i] if i!=n else 0 # To collect final area from the heights remaining in the stack
            while stk and h<stk[-1][1]:
                height = stk[-1][1]
                width = i-stk[-1][0]
                area = max(area,height*width)
                start = stk[-1][0]
                stk.pop()
            stk.append((start,h))
        
        return area