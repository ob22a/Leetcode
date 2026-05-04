class Solution:
    def findArray(self, pref: List[int]) -> List[int]:
        n=len(pref)

        sol = [pref[0]]
        for i in range(1,n):
            sol.append(pref[i-1]^pref[i])

        return sol