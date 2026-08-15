class Solution(object):
    def longestSubsequence(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        xor_all=0
        for i in nums:
            xor_all^=i
        nums.sort()
        n=len(nums)
        if xor_all>0:
            return len(nums)
        elif xor_all^nums[n-1]>0:
            return len(nums)-1
        return 0