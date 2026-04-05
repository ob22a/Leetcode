class Solution:
    def judgeCircle(self, moves: str) -> bool:
        state = [0,0] # vertical horizontal

        for move in moves:
            if move=="L":
                state[1]-=1
            elif move=="R":
                state[1]+=1
            elif move=="U":
                state[0]-=1
            else:
                state[0]+=1
        
        return state==[0,0]