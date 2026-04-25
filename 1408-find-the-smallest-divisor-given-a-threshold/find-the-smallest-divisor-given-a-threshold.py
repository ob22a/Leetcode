class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        l = max(sum(nums)//threshold,1)
        r = max(nums)

        def total(divisor):
            print("Divisor",divisor)
            t = 0
            for num in nums:
                t+=math.ceil(num/divisor)

            return t

        while l<r:
            m=(l+r)//2
            s = total(m)

            if s>threshold:
                l=m+1
            else:
                r=m
        
        return l