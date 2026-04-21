class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        n=len(weights)
        
        def isValid(weight,days):
            day = 1
            total = 0

            for i in range(len(weights)):
                if total+weights[i]>weight:
                    day+=1
                    total=0
                
                total+=weights[i]
            
            return day<=days

        left = max(weights)
        right = sum(weights)

        while left<right:
            mid = (left+right)//2
            if isValid(mid,days):
                right=mid
            else:
                left=mid+1
        
        return left