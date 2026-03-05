class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort()
        trainers.sort()

        trainer_idx = 0
        player_idx = 0

        trainers_size = len(trainers)
        players_size = len(players)
        sol = 0

        while player_idx<players_size and trainer_idx<trainers_size:
            if players[player_idx]<=trainers[trainer_idx]:
                sol+=1
                player_idx+=1
                trainer_idx+=1
            else: trainer_idx+=1
        
        return sol