class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums.sort()
        n = len(nums)
        sol=[]
        
        for i in range(n):
            if i>0 and nums[i]==nums[i-1]:
                continue
            
            left = i+1 
            right = n-1

            while left<right:
                if nums[left]+nums[right]==-nums[i]:
                    sol.append([nums[i],nums[left],nums[right]])
                    left+=1
                    while left<n and nums[left-1]==nums[left]:
                        left+=1
                    right-=1
                elif nums[left]+nums[right]<-nums[i]:
                    left+=1
                else:
                    right-=1

        return sol