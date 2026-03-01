class Solution:
    def convertToBase7(self, num: int) -> str:
        if num==0:
            return "0"
            
        sol = ""
        isNegative = False
        if num<0: 
            isNegative=True
            num*=-1

        while num!=0:
            sol+=str(num%7)
            num//=7
        
        if isNegative:
            sol+="-"

        return sol[::-1]
