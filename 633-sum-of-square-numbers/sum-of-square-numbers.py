class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        # a and b are less than or equal to sqrt of c-1
        # bs to find the answer 

        left, right = 0,int(c**0.5)

        while left <= right:
            curr = left * left + right * right
            
            if curr == c:
                return True
            elif curr < c:
                left += 1
            else:
                right -= 1

        return False
