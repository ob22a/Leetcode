class NumArray:

    def __init__(self, nums: list[int]):
        self.nums = nums
        self.n = len(self.nums)

        self.tree = [0]*(4*self.n)
        self._build(0,self.n-1,0)

    def _build(self,l,r,idx):
        if l==r:
            self.tree[idx]=self.nums[l]
            return
        
        mid = (l+r)//2
        left_idx = 2*idx + 1
        right_idx = 2*idx + 2

        self._build(l,mid,left_idx)
        self._build(mid+1,r,right_idx)

        self.tree[idx]=self.tree[left_idx]+self.tree[right_idx]
    
    def update(self, index: int, val: int) -> None:
        
        def update_tree(l,r,node):
            if l==r:
                self.tree[node] = val
                return 
            
            left_node = 2*node+1
            right_node = 2*node+2
            mid = (l+r)//2
            
            if l<=index<=mid: update_tree(l,mid,left_node)
            else: update_tree(mid+1,r,right_node)

            self.tree[node]=self.tree[left_node]+self.tree[right_node]

        update_tree(0,self.n-1,0)

    def sumRange(self, left: int, right: int) -> int:
        
        def solve(l,r,node):
            if l>=left and r<=right: return self.tree[node]
            elif r<left or l>right: return 0
            else: 
                left_node = 2*node+1
                right_node = 2*node+2
                mid = (l+r)//2

                return solve(l,mid,left_node) + solve(mid+1,r,right_node)

        return solve(0,self.n-1,0)


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)