class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        n = len(nums)
        def atMostCount(unique):
            ans = 0
            count = defaultdict(int)
            left = 0
            for right in range(n):
                count[nums[right]]+=1

                while len(count)>unique:
                    if count[nums[left]]==1:
                        count.pop(nums[left])
                    else:
                        count[nums[left]]-=1
                    left+=1
                
                ans+=right-left+1
                
            return ans
    
        return atMostCount(k)-atMostCount(k-1)