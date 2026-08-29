class BrowserHistory(object):
    def __init__(self, homepage):
        """
        :type homepage: str
        """
        self.lst=[homepage]
        self.cnt=0
        

    def visit(self, url):
        """
        :type url: str
        :rtype: None
        """
        self.lst=self.lst[0:self.cnt+1]
        self.cnt+=1
        self.lst.append(url)

    def back(self, steps):
        """
        :type steps: int
        :rtype: str
        """
        self.cnt = max(0, self.cnt-steps)
        return self.lst[self.cnt]
        
    def forward(self, steps):
        """
        :type steps: int
        :rtype: str
        """
        self.cnt=min(len(self.lst)-1,self.cnt+steps)
        return self.lst[self.cnt]

# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)