class Solution:
    def gcdSort(self, nums: list[int]) -> bool:
        # If correct position value and current one is connected at the UF then it can be sorted
        # generating UF with gcf for all combinations take O((n^2)logn) which is too slow so we can use the prime factors

        # We can generate the prime factors using spf
        n = len(nums)
        x = max(nums)
        root_max = int(x**0.5)

        spf = [i for i in range(x+1)]

        for i in range(2,root_max+1):
            if spf[i]==i:
                for j in range(i*i,x+1,i):
                    if spf[j]==j: spf[j]=i
        
        pf = defaultdict(set)
        
        for num in nums:
            factors = set()
            temp = num

            while temp!=1:
                factors.add(spf[temp])
                temp//=spf[temp]
            
            pf[num]=factors
        
        # now generate UF using what we have 

        parent = [i for i in range(n)]
        sz = [1]*n

        def find(x):
            if x==parent[x]:
                return x
            
            parent[x]=find(parent[x])
            return parent[x]
        
        def union(x,y):
            px = find(x)
            py = find(y)

            if px==py:
                return False
            
            if sz[px]>=sz[py]: 
                parent[py]=px
                sz[px]+=sz[py]
            else: 
                parent[px]=py
                sz[py]+=sz[py]
            
            return True

        owner = [-1]*(x+1)

        for i,num in enumerate(nums):
            print(i,num)
            for factor in pf[num]:
                if owner[factor] != -1:
                    union(owner[factor],i)
                owner[factor] = i
        
        srt = sorted((num, i) for i, num in enumerate(nums))

        for i, (_,org_idx) in enumerate(srt):
            if find(i) != find(org_idx):
                return False
        
        return True