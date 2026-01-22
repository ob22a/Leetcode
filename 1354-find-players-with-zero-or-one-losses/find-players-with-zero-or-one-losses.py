class Solution(object):
    def findWinners(self, matches):
        """
        :type matches: List[List[int]]
        :rtype: List[List[int]]
        """
        matchesLost = {}

        for win, lose in matches:
            if win not in matchesLost:
                matchesLost[win] = 0
            if lose not in matchesLost:
                matchesLost[lose] = 0
            matchesLost[lose] += 1

        allWin = []
        oneLose = []

        for player, losses in matchesLost.items():
            if losses == 0:
                allWin.append(player)
            elif losses == 1:
                oneLose.append(player)

        return [sorted(allWin), sorted(oneLose)]