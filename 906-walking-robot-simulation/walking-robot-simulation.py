class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        pos = [0,0] # x,y
        direction=[0,1] # meaning it moves upward

        setOfObstacles = set((x,y) for x,y in obstacles)
        sol = 0

        for move in commands:
            if move==-1:
                if direction[0]==0:
                    direction[0] = 1 if direction[1]>0 else -1
                    direction[1] = 0
                else:
                    direction[1] = -1 if direction[0]>0 else 1
                    direction[0] = 0
                continue
            
            if move==-2:
                if direction[0]==0:
                    direction[0] = -1 if direction[1]>0 else 1
                    direction[1] = 0
                else:
                    direction[1] = 1 if direction[0]>0 else -1
                    direction[0] = 0
                continue
            
            if direction[0]:
                # pos[0]+=direction[0]*move
                for _ in range(move):
                    if (pos[0]+direction[0],pos[1]) in setOfObstacles:
                        break
                    pos[0]+=direction[0]
            else:
                # pos[1]+=direction[1]*move
                for _ in range(move):
                    if (pos[0],pos[1]+direction[1]) in setOfObstacles:
                        break
                    pos[1]+=direction[1]
            
            sol = max(sol,pos[0]**2+pos[1]**2)
        
        return sol