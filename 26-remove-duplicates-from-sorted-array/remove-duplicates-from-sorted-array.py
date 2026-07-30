class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        write=1
        n=len(nums)
        for i in range(1,n):
            if nums[i]!=nums[i-1]:
                nums[write]=nums[i]
                write+=1
        return write
        