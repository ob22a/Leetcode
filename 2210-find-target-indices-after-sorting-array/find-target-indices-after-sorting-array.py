class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        def countingSort(nums,exp): # Stable version
            n = len(nums)
            sol =[0]*n
            count=[0]*10 # 0-9

            for num in nums:
                count[(num//exp)%10]+=1

            for i in range(1,10):
                count[i]+=count[i-1]

            for num in nums[::-1]:
                sol[count[(num//exp)%10]-1]=num
                count[(num//exp)%10]-=1
            
            for i in range(n):
                nums[i]=sol[i]

            return sol
        def radixSort(nums):
            exp = 1
            largest = max(nums)

            while largest//exp>0:
                countingSort(nums,exp)
                exp*=10
        
        sol = []
        radixSort(nums)
        
        for idx,num in enumerate(nums):
            if num==target:
                sol.append(idx)
        
        return sol