class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        score = []

        for c in s:
            if c=="(":
                score.append(0)
            else:
                sc = 0
                
                while score[-1]!=0:
                    sc+=score.pop()

                if sc==0:
                    sc=1
                else:
                    sc*=2
                
                score.pop()
                score.append(sc)
        
        return sum(score)