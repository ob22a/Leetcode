class Solution:
    def minimumDifference(self, nums):
        n = len(nums)
        m = n // 2
        total = sum(nums)

        def gen(arr):
            sums = defaultdict(list)

            def dfs(i, cnt, cur):
                if i == len(arr):
                    sums[cnt].append(cur)
                    return

                dfs(i + 1, cnt, cur)
                dfs(i + 1, cnt + 1, cur + arr[i])

            dfs(0, 0, 0)
            return sums

        left = gen(nums[:m])
        right = gen(nums[m:])

        for k in right:
            right[k].sort()

        ans = float("inf")

        for k in range(m + 1):
            A = left[k]
            B = right[m - k]

            for a in A:
                target = total / 2 - a

                idx = bisect_left(B, target)

                if idx < len(B):
                    chosen = a + B[idx]
                    ans = min(ans, abs(total - 2 * chosen))

                

        return ans