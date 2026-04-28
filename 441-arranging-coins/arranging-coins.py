class Solution:
    def arrangeCoins(self, n: int) -> int:
        left=1
        right=n

        while left<right:
            mid = (left+right+1)//2
            stairs = mid*(mid+1)//2

            if stairs>n:
                right=mid-1
            else:
                left=mid
        
        return left