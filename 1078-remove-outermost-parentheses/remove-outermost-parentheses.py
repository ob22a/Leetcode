class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        level = 0
        sol =[]

        for ch in s:
            if ch=="(":
                if level>0: sol.append(ch)
                level+=1
            else:
                level-=1
                if level>0: sol.append(ch)
        
        return "".join(sol)