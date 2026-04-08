class DataStream:

    def __init__(self, value: int, k: int):
        self.stk=[]
        self.value = value
        self.k=k

    def consec(self, num: int) -> bool:
        if num!=self.value:
            self.stk=[]
        else:
            self.stk.append(num)
        
        return len(self.stk)>=self.k


# Your DataStream object will be instantiated and called as such:
# obj = DataStream(value, k)
# param_1 = obj.consec(num)