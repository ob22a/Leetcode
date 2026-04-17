class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n<0:
            x=1/x
            n*=-1

        if n==0:
            return 1
            
        if n==1:
            return x

        val = self.myPow(x,n//2)
        
        if n%2==0:
            return val*val
        
        return x*val*val