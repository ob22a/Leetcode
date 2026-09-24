class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: list[int], rightChild: list[int]) -> bool:
        parent = list(range(n))
        rank = [1]*n
        has_parent = [False]*n
        
        def find(i):
            if parent[i]==i:
                return i
            
            parent[i]=find(parent[i])
            return parent[i]
        
        def union(x,y):
            root_x = find(x)
            root_y = find(y)

            if root_x==root_y:
                return False

            if rank[root_x]>=rank[root_y]:
                parent[root_y]=root_x
                rank[root_x]+=rank[root_y]
            else:
                parent[root_x]=root_y
                rank[root_y]+=rank[root_x]
            
            return True
        
        for i in range(n):
            l = leftChild[i]
            r = rightChild[i]

            if l!=-1:
                if has_parent[l]:
                    return False
                
                has_parent[l]=True

                if not union(i,l):
                    return False
            
            if r!=-1:
                if has_parent[r]:
                    return False
                
                has_parent[r]=True

                if not union(i,r):
                    return False

        root = find(0)

        for i in range(n):
            if find(i)!=root:
                return False
        
        return True