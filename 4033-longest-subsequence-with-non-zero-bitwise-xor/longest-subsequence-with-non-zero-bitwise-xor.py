class Solution(object):
    def longestSubsequence(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        xor_all,a=0,0
        for i in nums:
            xor_all^=i
            if i>0:
                a=i
        if a==0:
            return 0
        if xor_all>0:
            return len(nums)
        return len(nums)-1