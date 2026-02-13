class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        num_idx={}
        for idx,num in enumerate(nums):
            if num in num_idx:
                num_idx[num].append(idx)
            else: num_idx[num]=[idx]

        divisors = []
        for d in range(1,int(k**0.5)+1):
            if k%d==0:
                divisors.append(d)
                if d!=k/d:
                    divisors.append(k//d)
        print(divisors)
        sol = 0
        
        for idxs in num_idx.values():
            mp = Counter()
            for n in idxs:
                gcd = math.gcd(n,k)
                need = k/gcd
                sol+=mp[need]

                for d in divisors:
                    if n%d==0:
                        mp[d]+=1

        return sol