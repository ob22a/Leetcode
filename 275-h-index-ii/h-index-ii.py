class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n=len(citations)

        def isHIndex(num,n):
            idx = bisect_left(citations,num)
            return n-idx>=num
        
        left=0
        right=n

        while left<right:
            mid=(left+right+1)//2
            if isHIndex(mid,n):
                left=mid
            else:
                right=mid-1
        
        return left