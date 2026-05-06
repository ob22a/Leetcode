class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xor = reduce(lambda a,b:a^b,nums,0) # function iterator initializor 
        print(xor)
        r_most_one = xor & -xor
        print(r_most_one)

        sol = [0,0]

        for num in nums:
            if (r_most_one&num)==0:
                sol[0]^=num
            else:
                sol[1]^=num
        
        return sol