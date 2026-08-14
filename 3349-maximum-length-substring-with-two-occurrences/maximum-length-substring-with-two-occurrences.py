class Solution(object):
    def maximumLengthSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        i,j=0,0
        mp={}
        n=len(s)
        ans=0
        while j<n:
            mp[s[j]]=mp.get(s[j],0)+1
            while mp[s[j]]>2:
                mp[s[i]]-=1
                if mp[s[i]]==0:
                    del mp[s[i]]
                i+=1
            ans=max(ans,j-i+1)
            j+=1
        return ans