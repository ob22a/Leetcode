class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        cnt_target = 0
        cnt_less  = 0
        for num in nums:
            if num==target: cnt_target+=1
            elif num<target: cnt_less+=1
        
        return list(range(cnt_less,cnt_less+cnt_target))