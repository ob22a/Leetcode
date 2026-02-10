class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        sol = []
        col_map = {}
        color_count = {}

        for x,y in queries:
            if x in col_map:
                col = col_map[x]
                color_count[col]-=1
                if color_count[col]==0:
                    del color_count[col]
            col_map[x]=y
            color_count[y]=color_count.get(y,0)+1
            sol.append(len(color_count))

        return sol