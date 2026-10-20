class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        n = len(nums)

        fac = []
        for x in range(1, isqrt(n) + 1):
            if n % x == 0:
                fac.append(x)
                if n // x != x:
                    fac.append(n // x)

        target = sorted(nums)

        def validate(nums1, nums2):
            n = len(nums1)

            for i in range(n-1):
                if nums1[i] > nums1[i+1]:
                    return nums1[i+1:] + nums1[:i+1] == nums2

            return nums1==nums2

        ans = 0

        for d in fac:
            for left in range(0, n, d):
                right = left + d-1

                if not validate(nums[left : right + 1], target[left : right + 1]):
                    break
            else:
                ans += d

        return ans