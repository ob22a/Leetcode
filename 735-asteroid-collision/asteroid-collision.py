class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        n = len(asteroids)
        sol = [asteroids[0]]
        i=1
        while i<n:
            a = asteroids[i]
            if a>0 or (not sol or sol[-1]<0):
                sol.append(a)

            elif sol[-1]<-a:
                sol.pop()
                i-=1
            elif sol[-1]==-a:
                sol.pop()
            
            i+=1
        
        return sol