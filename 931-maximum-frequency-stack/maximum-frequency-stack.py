class FreqStack:

    def __init__(self):
        self.count = defaultdict(int)
        self.stackNum = defaultdict(list)
        self.mostFrequent = 0

    def push(self, val: int) -> None:
        self.count[val]+=1
        newFreq = self.count[val]

        if self.mostFrequent<newFreq:
            self.mostFrequent = newFreq

        self.stackNum[newFreq].append(val)

    def pop(self) -> int:
        freq = self.mostFrequent

        val = self.stackNum[freq].pop()
        self.count[val]-=1
        
        if self.count[val]==0:
            del self.count[val]
        
        if not self.stackNum[freq]:
            self.mostFrequent-=1
            del self.stackNum[freq]
                    
        return val


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()