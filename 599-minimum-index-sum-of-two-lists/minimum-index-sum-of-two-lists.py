class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        str_sum = {}
        sol_str_sum={}

        for idx,string in enumerate(list1):
            str_sum[string] = idx
        
        for idx,string in enumerate(list2):
            if string in str_sum:
                sol_str_sum[string] = idx + str_sum[string]

        print(sol_str_sum)
            
        smallest = 1e9
        sol = []
        for k,v in sol_str_sum.items():
            if v<smallest:
                sol = [k]
                smallest = v
            elif v==smallest:
                sol.append(k)
        
        return sol