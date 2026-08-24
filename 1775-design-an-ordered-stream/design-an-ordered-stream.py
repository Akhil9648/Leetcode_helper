class OrderedStream(object):

    def __init__(self, n):
        """
        :type n: int
        """
        self.lst=["" for i in range(n+1)]
        self.counter=1

    def insert(self, idKey, value):
        """
        :type idKey: int
        :type value: str
        :rtype: List[str]
        """
        self.lst[idKey]=value
        curr=[]
        while self.counter<len(self.lst) and self.lst[self.counter]!="":
            curr.append(self.lst[self.counter])
            self.counter+=1
        return curr
# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)