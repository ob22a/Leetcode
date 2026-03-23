class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        n = len(arr)
        seen = set()

        def visit(idx):
            if idx < 0 or idx >= n or idx in seen:
                return False
                
            if arr[idx]==0:
                return True
            
            seen.add(idx)
            return visit(idx+arr[idx]) or visit(idx-arr[idx])
        
        return visit(start)