class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxi,sum,curr,z=0,0,0,0
        for i in nums:
            maxi=max(maxi,i)
            curr+=i
            if i==0:
                z=1
        sum=maxi*(maxi+1)/2
        if curr<sum:
            return sum-curr
        if z==0:
            return 0
        return maxi+1