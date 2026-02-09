class Solution:
    def escapeGhosts(self, ghosts: List[List[int]], target: List[int]) -> bool:
        ghost_move = inf

        for ghost in ghosts:
            min_move = abs(ghost[0]-target[0])+abs(ghost[1]-target[1])
            ghost_move=min(ghost_move,min_move)
        
        my_move = abs(target[0])+abs(target[1])

        return my_move<ghost_move