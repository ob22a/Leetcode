class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n = len(arr)

        @cache
        def f(idx):
            if idx>=n:
                return 0
            
            length=0
            total=0
            max_=-1e10 
            end = min(n,idx+k)

            for j in range(idx,end):
                length+=1
                max_=max(max_,arr[j])
                total = max(total,max_*length+f(j+1))
            
            return total
        
        return f(0)