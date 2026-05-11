class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        n=len(nums)
        bitCount = [0]*32

        left=0
        val=0
        sol=float('inf')

        for right in range(n):
            val|=nums[right]
            binary = bin(nums[right])[2:]
            
            idx=31
            for c in binary[::-1]:
                if c=="1":
                    bitCount[idx]+=1
                idx-=1

            while left<=right and val>=k:
                sol=min(sol,right-left+1)

                binary_left = bin(nums[left])[2:]
                idx_left=31

                for ch in binary_left[::-1]:
                    if ch=="1":
                        bitCount[idx_left]-=1

                        if bitCount[idx_left]==0:
                            val = val & ~(1<<31-idx_left)
                    idx_left-=1
                
                left+=1
            
        
        return -1 if sol==float("inf") else sol