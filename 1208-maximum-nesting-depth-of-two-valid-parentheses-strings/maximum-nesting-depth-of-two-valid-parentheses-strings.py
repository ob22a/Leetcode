class Solution:
    def maxDepthAfterSplit(self, seq: str) -> list[int]:
        # thm2 feels like cf I can force the length to be 1 if I just alternate so 0 1 and so on 

        n = len(seq)
        sol = [0]*n

        stk = []
        a_turn = True

        for i,c in enumerate(seq):
            #print(stk,i,c)
            if c==")": # assuming all tc are VPS
                sol[stk.pop()]=0 if a_turn else 1
                sol[i]=0 if a_turn else 1
            
            else:
                stk.append(i)
            a_turn = not a_turn
        
        return sol