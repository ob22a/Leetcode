class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        n=len(nums)

        count=0
        maximum=0

        for mask in range(1,1<<n):
            res = 0
            for idx in range(n):
                if mask&(1<<idx):
                    res|=nums[idx]
            
            if res>maximum:
                maximum=res
                count=1
            elif res==maximum:
                count+=1
        
        return count