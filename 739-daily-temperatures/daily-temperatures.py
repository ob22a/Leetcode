class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        stk = []
        sol = [0]*n

        for i in range(n-1,-1,-1):
            while stk and temperatures[stk[-1]]<=temperatures[i]:
                stk.pop()
            if stk:
                sol[i]=stk[-1]-i
            stk.append(i)
        
        return sol