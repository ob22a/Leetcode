class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]: 
        n=len(arr)

        def b_left(num):
            left = 0
            right = len(arr)-1

            while left<right:
                mid = (left+right+1)//2
                if arr[mid]>num:
                    right=mid-1
                else:
                    left=mid
            
            # print(left)
            return left

        index = b_left(x)
        left,right = index,index+1
        # print(left,right)

        for _ in range(k):
            if left>=0 and right<n:
                left_diff = x-arr[left]
                right_diff = arr[right]-x
                if right_diff<left_diff:
                    right+=1
                else:
                    left-=1
            elif left>=0:
                left-=1
            else:
                right+=1
        
        return arr[left+1:right]