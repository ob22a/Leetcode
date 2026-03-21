class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        sol = [0]*n

        for first,last,seats in bookings:
            sol[first-1]+=seats
            if last<n: sol[last]-=seats
        
        for i in range(1,n):
            sol[i]+=sol[i-1]
        
        return sol