class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        mp={}
        i,n=0,len(s)
        maxi=0
        for j in range(n):
            mp[s[j]]=mp.get(s[j],0)+1
            while(mp[s[j]]>1):
                mp[s[i]]=mp.get(s[i],0)-1
                if mp[s[i]]==0:
                    del mp[s[i]]
                i+=1
            maxi=max(maxi,j-i+1)
            j+=1
        return maxi
        