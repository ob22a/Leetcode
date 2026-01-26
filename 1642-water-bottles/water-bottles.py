class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        total = numBottles
        empty = numBottles

        while(empty>=numExchange):
            new = empty//numExchange
            empty=empty%numExchange + new
            total+=new

        return total
