class Solution:
    def rotatedDigits(self, n: int) -> int:
        def isGood(num):
            diffRotationNumber = False

            while num:
                digit = num%10
                num//=10

                if digit==3 or digit==4 or digit==7:
                    return False
                
                if digit!=0 and digit!=1 and digit!=8:
                    diffRotationNumber=True

            return diffRotationNumber
        
        count = 0

        for num in range(1,n+1):
            if isGood(num):
                count+=1
        
        return count