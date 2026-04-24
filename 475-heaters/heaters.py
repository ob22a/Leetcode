class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        sol=0
        heaters.sort()
        n=len(heaters)

        for house in houses:
            idx = bisect_right(heaters,house)
            if idx==0:
                min_distance_heater=heaters[0]-house
            elif idx==n:
                min_distance_heater=house-heaters[idx-1]
            else:
                min_distance_heater = min(heaters[idx]-house,house-heaters[idx-1])
            
            sol=max(sol,min_distance_heater)

        return sol