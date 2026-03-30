class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        n = len(arr)
        arr.sort()

        sol = 1

        for i in range(n-1):
            if arr[i+1] == arr[i] and arr[i]<=sol:
                continue
            sol+=1
        
        return sol