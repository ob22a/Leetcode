class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def timeToEat(k):
            time = 0
            for b in piles:
                time+=(b+k-1)//k

            return time

        l=1
        r=max(piles)

        while l<r:
            m=(l+r)//2
            time = timeToEat(m)
            if time>h:
                l=m+1
            else:
                r=m
        
        return l