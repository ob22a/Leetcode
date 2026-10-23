class Solution:
    def longestPrefix(self, s: str) -> str:
        n = len(s)
        if n==1: return ""

        lps = [0]*n
        prev_lps,idx = 0,1

        while idx<n:
            if s[prev_lps]==s[idx]:
                lps[idx] = prev_lps + 1
                prev_lps+=1
                idx+=1
            elif prev_lps==0: idx+=1
            else: prev_lps = lps[prev_lps-1]
            
        return s[:lps[n-1]]