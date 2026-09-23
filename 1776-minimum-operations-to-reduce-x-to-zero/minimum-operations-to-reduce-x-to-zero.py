class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        # When we reverse our thinking we can look for longest subarray with sum sum(nums)-x

        n=len(nums)
        total = sum(nums)
        target = total-x

        summ=0
        sol=float('inf')
        l=0

        for r in range(n):
            summ+=nums[r]

            while summ>target and l<=r:
                summ-=nums[l]
                l+=1
            
            if summ==target:
                length = (l-0)+(n-1-r)
                sol = min(sol,length)
        
        return -1 if sol==float('inf') else sol