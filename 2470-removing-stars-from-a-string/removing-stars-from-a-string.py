class Solution:
    def removeStars(self, s: str) -> str:
        ls = []
        for c in s:
            if c=="*":
                if ls: ls.pop()
            else:
                ls.append(c)
        
        return "".join(ls)