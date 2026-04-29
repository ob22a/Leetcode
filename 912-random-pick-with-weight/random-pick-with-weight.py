class Solution:

    def __init__(self, w: List[int]):
        self.ps=[]
        total=0

        for weight in w:
            total+=weight
            self.ps.append(total)
        
        self.total=total

    def pickIndex(self) -> int:
        randNo = random.randint(1,self.total)
        return bisect_left(self.ps,randNo)


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()