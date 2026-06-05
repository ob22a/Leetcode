class Solution:
    def splitArraySameAverage(self, nums: List[int]) -> bool:
        n=len(nums)
        total = sum(nums)

        for i in range(n):
            nums[i]=nums[i]*n-total
        
        # Find a subset whose sum equals 0

        def gen(arr):
            sol=[]
            n=len(arr)

            def bkt(i,sum,sz):
                if i==n:
                    sol.append((sum,sz))
                    return
                
                return bkt(i+1,sum,sz) or bkt(i+1,sum+arr[i],sz+1)

            bkt(0,0,0)
            return sol
        
        left=gen(nums[:n//2])
        right=sorted(gen(nums[n//2:]))

        for left_sum,left_sz in left:
            idx = bisect_left(right,(-left_sum,left_sz))
            if idx<len(right):
                right_sum,right_sz = right[idx]
                total_sz = left_sz+right_sz

                if 0<total_sz<n and right_sum+left_sum==0:
                    return True
            if idx>0:
                right_sum,right_sz = right[idx-1]
                total_sz = left_sz+right_sz

                if 0<total_sz<n and right_sum+left_sum==0:
                    return True
        
        return False