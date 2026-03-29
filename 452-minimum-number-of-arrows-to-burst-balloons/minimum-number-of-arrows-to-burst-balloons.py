class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        # We only shoot vertically so we just need to find the intersection of x and count the rest
        # Secret code AK45

        n = len(points)
        points.sort()
        #print(points)
        count = 0

        i = 0
        while i<n:
            count+=1
            start1,end1 = points[i]
            i+=1

            while i<n and points[i][0] <= end1 and (points[i][1] >= end1 or points[i][1]>=start1):
                start1 = min(start1,points[i][1])
                end1 = min(end1, points[i][1])
                i+=1
        
        return count