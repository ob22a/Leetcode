class MyCalendar:

    def __init__(self):
        self.sch=[]

    def book(self, startTime: int, endTime: int) -> bool:
        time = (startTime,endTime)
        
        for s,e in self.sch:
            if not (time[1]<=s or time[0]>=e):
                return False
        
            
        self.sch.append(time)
        return True

        


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(startTime,endTime)