class Solution(object):
    def minimumPushes(self, word):
        """
        :type word: str
        :rtype: int
        """
        n=len(word)
        ans,cnt=0,1
        while(n):
            if(n>8):
                ans+=(8*cnt)
                n-=8
                cnt+=1
            else:
                ans+=n*cnt
                n=0
        return ans
        