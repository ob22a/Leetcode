class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        n = len(arr)
        sol = 1
        left = 0
        prev = 0

        for right in range(1,n):
            cur = (arr[right]>arr[right-1]) - (arr[right]<arr[right-1])
            if cur == 0:
                left = right
            elif cur*prev!=-1:
                left = right-1
            
            prev=cur
            sol=max(sol,right-left+1)
        
        return sol