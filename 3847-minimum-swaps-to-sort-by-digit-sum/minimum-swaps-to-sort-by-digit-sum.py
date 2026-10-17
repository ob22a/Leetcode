class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        arr = []
        n = len(nums)

        def sum_digits(num):
            res = 0
            while num:
                res+=num%10
                num//=10
            
            return res        
        
        for num in nums: arr.append((sum_digits(num),num))
        sorted_arr = sorted(arr) 
        sol = 0

        idx = {num:i for i,num in enumerate(sorted_arr)}
        
        # Cyclic sort
        for i in range(n):
            while arr[i] != sorted_arr[i]:
                j = idx[arr[i]]
                arr[i],arr[j]=arr[j],arr[i]
                sol+=1
        
        return sol
