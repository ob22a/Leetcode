class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        # Heater doesn't have to be in a house

        n=len(houses)
        m=len(heaters)
        posHeaters=set(heaters)

        houses.sort()
        heaters.sort()

        def warmAllHouses(radius):
            isWarm = [False]*n
            i=0
            j=0

            while i<n and j<m:
                lb=heaters[j]-radius
                ub=heaters[j]+radius

                if lb<=houses[i]<=ub:
                    isWarm[i]=True
                    i+=1
                else:
                    j+=1
            
            #print(isWarm,radius)
            return all(isWarm)


        l = 0
        r = max(max(houses),max(heaters))

        while l<r:
            mid=(l+r)//2

            if warmAllHouses(mid):
                r=mid
            else:
                l=mid+1
        
        #print(warmAllHouses(5))
        return l