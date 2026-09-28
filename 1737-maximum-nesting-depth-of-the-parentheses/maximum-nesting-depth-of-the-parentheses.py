class Solution:
    def maxDepth(self, s: str) -> int:
        count_left = 0
        sol = 0
        
        for c in s:
            if c=="(":
                count_left+=1
                sol = max(sol,count_left)
            elif c==")":
                count_left-=1
        
        return sol