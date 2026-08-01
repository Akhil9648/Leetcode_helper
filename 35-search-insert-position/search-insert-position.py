class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        ans=0
        low,high=0,len(nums)-1
        while low<=high:
            mid=(low+high)/2
            if nums[mid]==target:
                return mid
            elif nums[mid]>target:
                high=mid-1
                ans=mid
            else:
                low=mid+1
        if ans==0 and target>nums[0]:
            return len(nums)
        return ans