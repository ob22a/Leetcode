class Solution:
    def captureForts(self, forts: List[int]) -> int:
        n = len(forts)
        sol = 0

        l = 0
        r = 1

        while r<n:
            if forts[l]==0:
                l+=1
                r=l+1
                continue
            elif forts[r]==0:
                while r<n and forts[r]==0:
                    r+=1
                if r<n and forts[r]!=forts[l]: sol=max(sol,r-l-1)
            l=r
            r+=1
        
        return sol