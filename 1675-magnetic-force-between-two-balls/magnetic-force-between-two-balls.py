class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        n=len(position)
        position.sort()

        l=1
        r=position[n-1]-position[0]

        def isPossible(distance):
            count=1
            last=position[0]

            for pos in position:
                if last+distance<=pos:
                    last=pos
                    count+=1
                
                if count==m:
                    return True
            
            return False

        while l<r:
            mid=(l+r+1)//2
            if isPossible(mid): l=mid
            else: r=mid-1
        
        return r
        