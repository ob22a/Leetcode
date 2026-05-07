class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        a=0
        while left!=right:
            left>>=1
            right>>=1
            a+=1
        
        return left<<a