class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        product = 1
        zeroCount = 0

        for num in nums:
            if num==0:
                zeroCount+=1
            else: product*=num
        
        sol = []
        for num in nums:
            if num!=0: 
                if zeroCount:
                    sol.append(0)
                else:
                    sol.append(product//num)
            elif zeroCount==1:
                sol.append(product)
            else:
                sol.append(0)
            
        return sol