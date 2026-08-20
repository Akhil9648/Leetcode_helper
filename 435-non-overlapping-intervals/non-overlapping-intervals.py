class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        n=len(intervals)
        intervals=sorted(intervals,key=lambda x:(x[-1],x[0]))
        prev=intervals[0][1]
        cnt=0
        for i in range(1,n):
            if intervals[i][0]<prev:
                cnt+=1
            else:
                prev=intervals[i][1]
        return cnt