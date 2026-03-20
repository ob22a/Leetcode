class Solution:
    def longestSemiRepetitiveSubstring(self, s: str) -> int:
        n = len(s)
        sol = 0
        last = -1
        left = 0

        for right in range(n):
            sol = max(sol,right-left+1)
            
            if right<n-1 and s[right]==s[right+1]:
                left=last+1
                last = right
        
        return sol