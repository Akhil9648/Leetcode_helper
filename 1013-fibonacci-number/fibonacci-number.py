class Solution(object):
    def fib(self, n):
        """
        :type n: int
        :rtype: int
        """
        a,b=0,1
        while(n>0):
            c=a+b
            a=b
            b=c
            n-=1
        return a
        