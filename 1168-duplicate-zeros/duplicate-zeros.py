class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        amount = arr.count(0)
        i=0
        while i<len(arr):
            if arr[i]==0:
                arr.insert(i+1,0)
                i+=1
            i+=1
        
        for _ in range(amount):
            arr.pop()