class Solution:
    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        seats.sort()
        students.sort()

        moves = sum(abs(x-y) for x,y in zip(seats,students))

        return moves