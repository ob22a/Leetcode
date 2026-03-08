class Solution:
    def duplicateZeros(self, arr):
        n = len(arr)
        zeros = 0

        for i in range(n):
            if i + zeros >= n:
                break
            if arr[i] == 0:
                if i + zeros == n - 1:
                    arr[n - 1] = 0
                    n -= 1
                    break
                zeros += 1

        last = n - zeros - 1

        # Move backwards
        for i in range(last, -1, -1):
            if arr[i] == 0:
                arr[i + zeros] = 0
                zeros -= 1
                arr[i + zeros] = 0
            else:
                arr[i + zeros] = arr[i]