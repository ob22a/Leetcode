class Solution:
    def mySqrt(self, x: int) -> int:
        isNegative = x<0
        if isNegative:
            x*=-1

        l=0
        r=(x+1)//2

        while l<r:
            m=(l+r+1)//2
            sqr = m*m

            if sqr==x:
                return m
            
            if sqr>x:
                r=m-1
            else:
                l=m
        
        return r
