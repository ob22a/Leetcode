class Solution:
    def isValid(self, s: str) -> bool:
        mapp = {")":"(","]":"[","}":"{"}
        stk = []
        for c in s:
            if c in mapp:
                if not stk or stk.pop() !=mapp[c]:
                    return False
            else:
                stk.append(c)
        
        return not stk
                