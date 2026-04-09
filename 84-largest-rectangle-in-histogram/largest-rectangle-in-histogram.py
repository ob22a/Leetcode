class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        stk = [] # Monotonic increassing stack holding val idx
        sol = 0

        for i in range(n+1):
            start=i # Rectangle with height heights[i] starts at this point
            h = heights[i] if i!=n else 0
            while stk and stk[-1][0]>=h:
                height = stk[-1][0]
                width = i - stk[-1][1]
                sol = max(sol,height*width)
                start = stk[-1][1]

                stk.pop()
            
            if i!=n: 
                stk.append((heights[i],start))
        
        return sol