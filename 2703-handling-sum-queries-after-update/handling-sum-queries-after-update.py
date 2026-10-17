class Solution:
    def handleQuery(self, nums1: List[int], nums2: List[int], queries: List[List[int]]) -> List[int]:
        n = len(nums1)
        tree = [0]*(4*n)
        lazy = [False]*(4*n)

        def build(l,r,node):
            if l==r: 
                tree[node]=nums1[l]
                return
            
            left_node = 2*node+1
            right_node = 2*node+2
            mid = (r+l)//2

            build(l,mid,left_node)
            build(mid+1,r,right_node)

            tree[node]=tree[left_node]+tree[right_node]
        
        def update(start,end,l,r,node):
            left_node = 2*node+1
            right_node = 2*node+2
            mid = (l+r)//2
            rng = r-l+1

            if lazy[node]:
                lazy[node]=False
                tree[node]=rng-tree[node]

                if l!=r:
                    lazy[left_node] = not lazy[left_node]
                    lazy[right_node]= not lazy[right_node] 
            
            if start<=l and end>=r:
                tree[node] = rng-tree[node]

                if l!=r:
                    lazy[left_node] = not lazy[left_node]
                    lazy[right_node]= not lazy[right_node]   

                return 
            
            elif r<start or l>end: return 
            else:
                update(start,end,l,mid,left_node)
                update(start,end,mid+1,r,right_node)

            tree[node]=tree[left_node]+tree[right_node]
        
        build(0,n-1,0)
        total = sum(nums2)
        sol = []

        for q,l,r in queries:
            if q==1: update(l,r,0,n-1,0)
            elif q==2: total+= tree[0] * l
            else: sol.append(total)
        
        return sol
