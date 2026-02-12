class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        m,n = len(img), len(img[0])
        sol = [[0]*n for _ in range(m)]

        directions = [-1,0,1]

        for r in range(m):
            for c in range(n):
                total = 0
                count = 0

                for dc in directions:
                    for dr in directions:
                        nr,nc=r+dr,c+dc
                        if 0 <=nr< m and 0<=nc< n:
                            total += img[nr][nc]
                            count += 1
                sol[r][c]=total//count

        return sol

                