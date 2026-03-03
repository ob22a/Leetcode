class Solution:
    def mergeStones(self, stones: List[int], k: int) -> int:
        n = len(stones)
        if (n-1)%(k-1)!=0:
            return -1

        prefix = [0]*(n+1)
        for i in range(n):
            prefix[i+1]=prefix[i]+stones[i]
        
        def rangeSum(i,j):
            return prefix[j+1]-prefix[i]

        @lru_cache(None)
        def f(left,right):
            if left==right:
                return 0

            length = right - left +1
            sol = float('inf')
            for mid in range(left,right,k-1):
                l = f(left,mid)
                r = f(mid+1,right)
                sol = min(sol,l+r)
            
            if (length-1)%(k-1)==0:
                sol+=rangeSum(left,right)
            
            return sol

        return f(0,n-1)