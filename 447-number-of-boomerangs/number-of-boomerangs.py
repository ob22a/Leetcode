class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        def dist(p1,p2):
            return (p1[0]-p2[0])**2 + (p1[1]-p2[1])**2

        n = len(points)
        sol = 0

        for i in points:
            dist_map = Counter()
            
            for j in points:
                if i==j: continue 

                distance = dist(i,j)
                dist_map[distance]+=1

            for count in dist_map.values():
                sol+=count*(count-1)

        return sol