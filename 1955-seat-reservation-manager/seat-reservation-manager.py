import heapq
class SeatManager:
    def __init__(self, n: int):
        self.minheap=[]
        self.counter=1

    def reserve(self) -> int:
        if self.minheap:
            return heapq.heappop(self.minheap)
        a=self.counter
        self.counter+=1
        return a

    def unreserve(self, seatNumber: int) -> None:
        heapq.heappush(self.minheap,seatNumber)


# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)