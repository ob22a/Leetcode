class Solution:
    def minAbsDifference(self, nums: List[int], goal: int) -> int:
        n=len(nums)
        sol=float('inf')

        def gen(arr):
            sums=[]

            def dfs(i,sum):
                if i>=len(arr):
                    sums.append(sum)
                    return
                
                dfs(i+1,sum)
                dfs(i+1,sum+arr[i])
            
            dfs(0,0)
            return sums
        
        left = gen(nums[:n//2])
        right = gen(nums[n//2:])
        right.sort()

        #print(left,right)

        for num in left:
            x = goal-num
            idx = bisect_left(right,x)
            #print(x,idx)
            
            if idx<len(right):
                sum_val = num+right[idx]
                sol=min(sol,abs(goal-sum_val))

            if idx>0:
                sum_val=num+right[idx-1]
                sol=min(sol,abs(goal-sum_val))
        
        return sol