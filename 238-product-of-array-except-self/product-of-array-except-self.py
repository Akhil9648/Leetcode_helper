class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        pre,suff=[],[]
        curr=1
        n=len(nums)
        for i in range(n-1,-1,-1):
            suff.append(curr)
            curr*=nums[i]
        curr=1
        suff.reverse()
        for i in range(n):
            pre.append(curr)
            curr*=nums[i]
        ans=[]
        for i in range(n):
            ans.append(pre[i]*suff[i])
        return ans