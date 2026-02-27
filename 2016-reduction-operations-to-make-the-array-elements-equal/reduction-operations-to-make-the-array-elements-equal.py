class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        x = sorted((val,cnt) for val,cnt in cnt.items())
        n = len(x)
        sol = 0

        cumm = 0
        for i in range(n-1,0,-1):
            sol+=cumm+x[i][1]
            cumm+=x[i][1]

        return sol