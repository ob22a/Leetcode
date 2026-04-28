class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n=len(matrix)

        def count_le(num):
            count = 0
            row = n-1
            col = 0

            while row>=0 and col<n:
                if matrix[row][col]<=num:
                    count+=row+1
                    col+=1
                else:
                    row-=1
            
            return count
        
        left = matrix[0][0]
        right = matrix[n-1][n-1]

        while left<right:
            mid = (left+right)//2

            if count_le(mid)<k:
                left=mid+1
            else:
                right=mid
        
        return left