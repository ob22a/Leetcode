class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        n = len(nums)
        total = 0

        for i in range(k):
            total+=nums[i]

        average = total/k
        
        left=0
        for right in range(k,n):
            total+=nums[right]-nums[left]
            left+=1
            average=max(average,total/k)
        
        return average