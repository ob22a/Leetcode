class Robot:

    def __init__(self, width: int, height: int):
        self.w=width
        self.h=height
        self.pos = 0
        self.perimeter = self.w*2+self.h*2-4
        self.moved = False

    def step(self, num: int) -> None:
        self.pos = (self.pos + num) % self.perimeter
        self.moved = True
            
                
    def getPos(self) -> List[int]:
        p = self.pos
        
        if p < self.w:
            return [p, 0]
        p -= self.w
        
        if p < self.h - 1:
            return [self.w - 1, p + 1]
        p -= (self.h - 1)
        
        if p < self.w - 1:
            return [self.w - 2 - p, self.h - 1]
        p -= (self.w - 1)
        
        return [0, self.h - 2 - p]

    def getDir(self) -> str:
        if not self.moved:
            return "East"
        
        p = self.pos
        
        if p == 0:
            return "South"
        if p < self.w:
            return "East"
        if p < self.w + self.h - 1:
            return "North"
        if p < 2*self.w + self.h - 2:
            return "West"
        return "South"

# Your Robot object will be instantiated and called as such:
# obj = Robot(width, height)
# obj.step(num)
# param_2 = obj.getPos()
# param_3 = obj.getDir()