class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        sol = 0
        points.sort()
        n = len(points)

        for i in range(n-1):
            sol=max(sol,points[i+1][0]-points[i][0])
        
        return sol