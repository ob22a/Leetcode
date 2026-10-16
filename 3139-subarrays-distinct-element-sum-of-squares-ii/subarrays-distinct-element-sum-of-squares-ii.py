class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)

        sums = [0] * (4 * n)
        squares = [0] * (4 * n)
        lazy = [0] * (4 * n)

        def apply(node, length, x):
            squares[node] = (squares[node] + 2 * x * sums[node] + length * x * x) % MOD

            sums[node] = (sums[node] + length * x) % MOD
            lazy[node] += x

        def push(node, left, right):
            if lazy[node] == 0 or left == right:
                return

            mid = (left + right) // 2
            x = lazy[node]

            apply(node * 2, mid - left + 1, x)
            apply(node * 2 + 1, right - mid, x)

            lazy[node] = 0

        def update(node, left, right, ql, qr):
            if ql <= left and right <= qr:
                apply(node, right - left + 1, 1)
                return

            push(node, left, right)
            mid = (left + right) // 2

            if ql <= mid:
                update(node * 2, left, mid, ql, qr)

            if qr > mid:
                update(node * 2 + 1, mid + 1, right, ql, qr)

            sums[node] = (sums[node * 2] + sums[node * 2 + 1]) % MOD
            squares[node] = (squares[node * 2] + squares[node * 2 + 1]) % MOD

        last = {}
        ans = 0

        for r, x in enumerate(nums):
            p = last.get(x, -1)
            update(1, 0, n - 1, p + 1, r)

            ans = (ans + squares[1]) % MOD
            last[x] = r

        return ans