class Solution(object):
    dr = [0, 1, 0, -1]
    dc = [1, 0, -1, 0]
    def solve(self,i,j,grid,vis,n,m):
        vis[i][j]=1
        for k in range(0,4):
            r=i+self.dr[k]
            c=j+self.dc[k]
            if(r>=0 and r<n and c>=0 and c<m and vis[r][c]==0 and grid[r][c]=='1'):
                self.solve(r,c,grid,vis,n,m)
        return
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        r=len(grid)
        c=len(grid[0])
        cnt=0
        vis=[[0 for j in range (c)] for i in range (r)]
        for i in range(r):
            for j in range(c):
                if(vis[i][j]==0 and grid[i][j]=='1'):
                    cnt+=1
                    self.solve(i,j,grid,vis,r,c)
        return cnt