class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        # Simplest approach is to duplicate and compute 
        n = len(nums)
        nums = nums*2
        sol = [-1]*(2*n)
        stk = []

        for i in range(2*n-1,-1,-1):
            while stk and stk[-1]<=nums[i]:
                stk.pop()
            
            if stk:
                sol[i]=stk[-1]
            
            stk.append(nums[i])
        
        return sol[:n]