class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        n=len(nums)
        no_odd = 0
        left = 0

        sol=0
        no_evens=0

        for right in range(n):
            if nums[right]%2==1:
                no_odd+=1

            if no_odd>k:
                no_evens=0
            
            while no_odd>k:
                if nums[left]%2==1:
                    no_odd-=1
                left+=1
            
            while left<=right and nums[left]%2==0:
                left+=1
                no_evens+=1
            
            if no_odd==k:
                sol+=no_evens+1            

        return sol

        # 2 2 1 1 2 2 1 k=2