class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        n=len(nums)
        arr = [abs(num) for num in nums]
        arr.sort()

        sol=0 
        left,right=0,n-1

        while left<=right:
            if left!=right:
                sol-=arr[left]**2
                left+=1
            sol+=arr[right]**2
            right-=1
        
        return sol