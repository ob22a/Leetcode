class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)

        sums = [0] * (4*n)
        squares = [0] * (4*n)
        lazy = [0] * (4*n)

        """
        T' = T + lx and S' = S + 2Sx + kx^2 , where 
        l is the length or range
        x is the number of update 
        T is total unique numbers 
        S sum of square of Ts

        x is usually 1 be we don't just assume that and ignore it in lazy propagation it could accumulate
        """

        def update(node,left,right,start,end):
            left_node = 2*node+1
            right_node = 2*node+2

            length = right-left+1
            mid = (right+left)//2

            if lazy[node]:
                squares[node] += 2*sums[node]*lazy[node] + length*lazy[node]**2
                sums[node]+=length*lazy[node]

                if left!=right:
                    lazy[left_node]+=lazy[node]
                    lazy[right_node]+=lazy[node]
                
                lazy[node]=0
            
            if start<=left and right<=end:
                squares[node]=(squares[node] + 2*sums[node] + length)%MOD
                sums[node] = (sums[node] + length)%MOD

                if left!=right:
                    lazy[left_node]+=1
                    lazy[right_node]+=1
                
                return
            
            elif end<left or start>right:
                return
            else:
                update(left_node,left,mid,start,end)
                update(right_node,mid+1,right,start,end)
            
            sums[node]=(sums[left_node]+sums[right_node])%MOD
            squares[node]=(squares[left_node]+squares[right_node])%MOD
            
        last = {}
        ans = 0

        for r, x in enumerate(nums):
            p = last.get(x, -1)
            update(0, 0, n - 1, p + 1, r)

            ans = (ans + squares[0]) % MOD
            last[x] = r

        return ans
