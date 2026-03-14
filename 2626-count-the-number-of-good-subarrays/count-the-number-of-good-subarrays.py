class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        n = len(nums)
        count = defaultdict(int)
        left = 0
        cur_k = 0
        good_subarray_count = 0

        for right in range(n):
            count[nums[right]]+=1
            cur_k += count[nums[right]]-1

            while cur_k>=k:
                good_subarray_count += n-right

                cur_k -= count[nums[left]]-1
                count[nums[left]]-=1
                left+=1
        
        return good_subarray_count