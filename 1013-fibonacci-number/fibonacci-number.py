class Solution:
    def fib(self, n: int) -> int:
        a,b=0,1
        for _ in range(n):
            temp=a
            a=b
            b+=temp
        
        return a