class Solution:
    def clearDigits(self, s: str) -> str:
        sol=[]
        for c in s:
            if sol and c.isdigit():
                sol.pop()
            else:
                sol.append(c)
        
        return "".join(sol)