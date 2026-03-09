class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        n1=len(g)
        n2=len(s)

        g.sort()
        s.sort()

        greed_idx=n1-1
        cookie_idx=n2-1

        count = 0
        while greed_idx>=0 and cookie_idx>=0:
            if g[greed_idx]<=s[cookie_idx]:
                count+=1
                cookie_idx-=1
            greed_idx-=1

        return count
