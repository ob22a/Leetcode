class Solution:
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        self.sol=float('inf')
        all_bags = [0]*k
        cookies.sort(reverse=True)

        def bkt(i):
            if i>=len(cookies):
                self.sol=min(self.sol,max(all_bags))
                return 
            
            for j in range(k):
                all_bags[j]+=cookies[i]
                if all_bags[j]<self.sol:
                    bkt(i+1)
                all_bags[j]-=cookies[i]
        
        bkt(0)
        
        return self.sol