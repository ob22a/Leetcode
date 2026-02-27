class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        n = len(intervals)
        i=0
        sol = []

        while i<n:
            start1=intervals[i][0]
            end1=intervals[i][1]

            while i<n-1 and end1>=intervals[i+1][0]:
                end1=max(end1,intervals[i+1][1])
                i+=1

            sol.append([start1,end1])
            i+=1

        return sol