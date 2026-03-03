class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        n = len(nums)
        sol = 0
        acc = 0
        counter = {0:1}

        for i in range(n):
            acc+=nums[i]
            if acc%k in counter:
                sol+=counter[acc%k]
                counter[acc%k]+=1
            else: counter[acc%k]=1
        
        return sol