class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        sol = []

        s=sum
        n=num

        while s and n:
            digit = 9 if s>=9 else s
            
            sol.append(digit)
            s-=digit
            n-=1
        
        if reduce(lambda x,y:x+y, sol)!=sum: return ""

        diff = num-len(sol)
        sol.extend([0]*diff)

        return "".join([str(x) for x in sol])