class Solution:
    def maximumTastiness(self, price: List[int], k: int) -> int:
        # Maximum gap between each price
        """
            What can the answer be range
            1 - max-min
            1 2 5 8 13 21
        """
        n = len(price)
        price.sort()

        def isValid(max_tastiness):
            last_candy = 0
            basket = 1

            for idx in range(1,n):
                if price[idx]>=price[last_candy]+max_tastiness:
                    last_candy = idx
                    basket+=1
            
            return basket>=k

        # Outer loop can be replaced with bs
        left = 0
        right = price[-1]-price[0]

        while left<right:
            mid = left + (right-left)//2 + 1 
            if isValid(mid):
                left = mid
            else:
                right = mid-1

        return left