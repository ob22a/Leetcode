class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        def maxAreaInHistogram(heights):
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
        
        n,m=len(matrix),len(matrix[0])
        dp = [0]*m
        sol = 0

        for i in range(n):
            for j in range(m):
                dp[j] = dp[j]+1 if matrix[i][j]=="1" else 0
            sol=max(sol,maxAreaInHistogram(dp))
        
        return sol