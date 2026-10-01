class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        def has_leap(year):
            return year%400==0 or (year%4==0 and year%100!=0)
        
        days_of_week = ["Friday","Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday"]
        month_days = [31,28,31,30,31,30,31,31,30,31,30,31]

        def total_days(d,m,y):
            total = 0

            for yr in range(1971,y):
                total += 365 + has_leap(yr)
            
            total += sum(month_days[:m-1])
            total += d

            if m>2:
                total+=has_leap(y)
            
            return total
            
        total_start = total_days(1,1,1971)
        total_end = total_days(day,month,year)

        return days_of_week[(total_end-total_start)%7]
