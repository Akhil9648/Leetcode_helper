import heapq
class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        mheap=[]
        for i in nums:
            heapq.heappush(mheap,i)
            if len(mheap)>k:
                heapq.heappop(mheap)
        return mheap[0]
        