class Solution:
    def checkDivisibility(self, n: int) -> bool:
        sum,mul=0,1
        num=n
        while num:
            d=num%10
            sum+=d
            mul*=d
            num//=10
        return (n%(sum+mul)==0)