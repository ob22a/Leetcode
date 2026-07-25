class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        # MST
        n=len(points)
        pq=[(0,points[0],None)] # cost point parent
        visited = set()

        sol=0
        while pq:
            cost,pt,parent = heappop(pq)
            if tuple(pt) in visited: continue
            
            visited.add(tuple(pt))
            sol+=cost

            for point in points:
                if point!=pt and not tuple(point) in visited:
                    new_cost = abs(pt[0]-point[0])+abs(pt[1]-point[1])
                    heappush(pq,(new_cost,point,pt))
        
        return sol