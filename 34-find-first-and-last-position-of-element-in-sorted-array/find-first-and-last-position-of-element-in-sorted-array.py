class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n=len(nums)

        def helper(left,right,isFirst):
            ans = -1
            while left<=right:
                mid = (left+right)//2
                if nums[mid]==target:
                    ans = mid
                    if isFirst:
                        right = mid-1
                    else:
                        left = mid+1
                
                elif nums[mid]<target:
                    left=mid+1
                else:
                    right=mid-1
            return ans

        return [helper(0,n-1,True),helper(0,n-1,False)] 