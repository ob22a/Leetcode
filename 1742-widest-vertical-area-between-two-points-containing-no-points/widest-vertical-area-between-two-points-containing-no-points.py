class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        n = len(points)
        sol = 0
        x=sorted(points[i][0] for i in range(n))

        for i in range(n-1):
            sol=max(sol,x[i+1]-x[i])
        
        return sol