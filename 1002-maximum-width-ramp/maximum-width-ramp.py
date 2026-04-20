class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        mtk_dec = []
        for idx,num in enumerate(nums):
            if not mtk_dec or nums[mtk_dec[-1]]>num:
                mtk_dec.append(idx)
        sol = 0
        for i in range(len(nums)-1,-1,-1):
            while mtk_dec and nums[i]>=nums[mtk_dec[-1]]:
                sol=max(sol,i-mtk_dec.pop())
        
        return sol