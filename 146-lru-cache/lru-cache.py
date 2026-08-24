class Node:
    def __init__(self,key,value):
        self.key=key
        self.value=value
        self.prev=None
        self.next=None
class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.map={}
        self.cap=capacity
        self.head=Node(-1,-1)
        self.tail=Node(-1,-1)
        self.head.next=self.tail
        self.tail.prev=self.head
    def add_node(self,node):
        nxt=self.head.next
        node.next=nxt
        self.head.next=node
        nxt.prev=node
        node.prev=self.head
    def remove(self,node):
        nxt=node.next
        prv=node.prev
        nxt.prev=prv
        prv.next=nxt
    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key in self.map:
            node=self.map[key]
            self. remove(node)
            self.add_node(node)
            return node.value
        return -1

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        if key in self.map:
            node=self.map[key]
            self.remove(node)
            self.add_node(node)
            node.value=value
            return
        if len(self.map)>=self.cap:
            node=self.tail.prev
            self.remove(node)
            del self.map[node.key]
        node=Node(key,value)
        self.add_node(node)
        self.map[key]=node

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)