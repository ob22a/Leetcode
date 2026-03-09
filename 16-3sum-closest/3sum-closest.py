class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        diff = float('inf')
        result = 0

        n=len(nums)
        nums.sort()

        for i in range(n):
            if i!=0 and nums[i]==nums[i-1]:
                continue
            
            left = i+1
            right = n-2 if i==n-1 else n-1

            while left<right:
                res = nums[i]+nums[left]+nums[right]
                if abs(target-res)<diff:
                    diff=abs(target-res)
                    result=res

                if res<target:
                    left+=1
                elif res>target:
                    right-=1
                else:
                    return target
        
        return result