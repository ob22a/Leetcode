class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        n=len(intervals)
        startIdx = {intervals[i][0]:i for i in range(n)}
        start = [start for start,_ in intervals]
        start.sort()

        sol = []
        for interval in intervals:
            end = interval[1]
            index = bisect_left(start,end)
            val = -1 if index>=len(start) else startIdx[start[index]]

            sol.append(val)
        
        return sol
