class Solution(object):
    def resultArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        l1,l2=[],[]
        n=len(nums)
        l1.append(nums[0])
        l2.append(nums[1])
        for i in range(2,n):
            if l1[-1]>l2[-1]:
                l1.append(nums[i])
            else:
                l2.append(nums[i])
        l1.extend(l2)
        return l1