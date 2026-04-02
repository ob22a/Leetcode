class Node:
    def __init__(self,val=-1,next=None,prev=None):
        self.val=val
        self.prev=prev
        self.next=next

class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.nodeMap = dict()
        self.length = 0
        self.head = None
        self.tail=None

    def moveToTail(self,node):
        if node == self.head and self.head!=self.tail:
            self.head=self.head.next
            
        if node.next: 
            if node.prev: 
                node.prev.next = node.next
            node.next.prev = node.prev

            self.tail.next=node
            node.prev = self.tail
            node.next = None
            self.tail = node

    def get(self, key: int) -> int:
        if key not in self.nodeMap:
            return -1
        
        node = self.nodeMap[key]
        self.moveToTail(node)

        return node.val[1]
        
    def put(self, key: int, value: int) -> None:
        if key in self.nodeMap:
            node = self.nodeMap[key]
            node.val = (key,value)
            
            self.moveToTail(node)
            return
        
        newNode = Node((key,value))
        if self.tail is None:
            self.head=newNode
            self.tail=newNode
        else:
            self.tail.next=newNode
            newNode.prev=self.tail
            self.tail=newNode

            if self.length == self.capacity:
                k = self.head.val[0]
                del self.nodeMap[k]

                self.head = self.head.next
                self.head.prev = None

        self.nodeMap[key]=newNode
        
        if self.length<self.capacity:
            self.length+=1


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)