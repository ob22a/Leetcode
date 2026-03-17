class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        n = len(blocks)
        w_count = 0
        b_count = 0

        sol = float('inf')
        left = 0

        for right in range(n):
            if blocks[right]=="W":
                w_count+=1
            else:
                b_count+=1

            if right-left+1==k:
                sol=min(sol,w_count)
                if blocks[left]=="W":
                    w_count-=1
                else:
                    b_count-=1
                left+=1
            
        return sol