class Solution:
    def hasValidPath(self, grid: list[list[int]]) -> bool:
        # 3 and 5 need to be to the right 
        # 4 and 6 need to be to the left 
        # 3 and 4 need to be top and 5 and 6 should be bottom 
        # 1 should be horizontal 2 should be vertical 

        m,n=len(grid),len(grid[0])
        seen = set()

        directions = {
            1: {'l', 'r'},
            2: {'t', 'b'},
            3: {'l', 'b'},
            4: {'r', 'b'},
            5: {'l', 't'},
            6: {'r', 't'}
        }

        opposite = {
            'r': 'l',
            'l': 'r',
            'b': 't',
            't': 'b'
        }

        def valid_move(x, y, direction):
            return (direction in directions[x] and opposite[direction] in directions[y])


        def dfs(i,j):
            if (not 0<=i<m) or (not 0<=j<n) or (i,j) in seen:
                return False

            if i==m-1 and j==n-1:
                return True
            
            seen.add((i,j))
            
            for dx,dy,dir in [(1,0,'b'),(0,1,'r'),(-1,0,'t'),(0,-1,'l')]:
                nx=i+dx
                ny=j+dy

                if 0<=nx<m and 0<=ny<n and valid_move(grid[i][j],grid[nx][ny],dir):
                    if dfs(nx,ny):
                        return True
            
            return False

        return dfs(0,0)