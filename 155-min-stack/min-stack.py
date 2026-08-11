import heapq
class MinStack(object):
    def __init__(self):
        self.minheap=[]
        self.stack=[]
    def push(self, value):
        """
        :type value: int
        :rtype: None
        """
        self.stack.append(value)
        heapq.heappush(self.minheap,value)
    def pop(self):
        """
        :rtype: None
        """
        if not self.stack:
            return
        a=self.stack.pop()
        hp=[]
        while self.minheap and self.minheap[0]!=a:
            b=heapq.heappop(self.minheap)
            hp.append(b)
        if self.minheap:
            heapq.heappop(self.minheap)
        for i in hp:
            heapq.heappush(self.minheap, i)

    def top(self):
        """
        :rtype: int
        """
        return self.stack[-1]

    def getMin(self):
        """
        :rtype: int
        """
        if self.minheap:
            return self.minheap[0]
        return None
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(value)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()