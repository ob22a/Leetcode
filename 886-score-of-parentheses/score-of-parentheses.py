class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        score = [0]

        for c in s:
            if c=="(":
                score.append(0)
            else:
                val=max(2*score.pop(),1)
                score[-1]+=val

        return score.pop()