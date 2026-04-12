class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        stk=[]
        n=len(nums)
        maximum=-float('inf')
        popped = False

        for i in range(n-1,-1,-1):
            # print(stk,maximum)
            if stk and popped and nums[i]<stk[-1] and nums[i]<maximum:
                return True

            while stk and stk[-1]<nums[i]:
                val = stk.pop()
                popped=True
                if val>maximum:
                    maximum=val
            
            stk.append(nums[i])
        
        return False
            