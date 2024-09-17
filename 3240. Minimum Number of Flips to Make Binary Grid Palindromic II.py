class Solution(object):
    def minFlipsBoundary(self, x1, x2, y1, y2, numTwos, numOnes):
        m = x2 - x1
        n = y2 - y1
        if m == 0 or n == 0:
            if numOnes > 0:
                numTwos = 0
            return numOnes + numTwos * 2
        if m == 1 and n == 1:
            if numOnes > 0:
                numTwos = 0
            if self.grid[x1][y1] == 1:
                return numOnes + numTwos * 2 + 1
            return numOnes + numTwos * 2
        minFlips = 0
        if m == 1:
            if n % 2 == 1:
                minFlips += self.grid[x1][y1+n/2]
            for i in range(n/2):
                if self.grid[x1][y1+i] + self.grid[x1][y2-1-i] == 2:
                    numTwos += 1
                elif self.grid[x1][y1+i] + self.grid[x1][y2-1-i] == 1:
                    numOnes += 1
            numTwos = numTwos % 2
            if numOnes > 0:
                numTwos = 0
            return minFlips + numOnes + numTwos * 2
        elif n == 1:
            if m % 2 == 1:
                minFlips += self.grid[x1+m/2][y1]
            for i in range(m/2):
                if self.grid[x1+i][y1] + self.grid[x2-i-1][y1] == 2:
                    numTwos += 1
                elif self.grid[x1+i][y1] + self.grid[x2-i-1][y1] == 1:
                    numOnes += 1
            numTwos = numTwos % 2
            if numOnes > 0:
                numTwos = 0
            return minFlips + numOnes + numTwos * 2
        else:
            for i in range(n/2):
                fourVals = self.grid[x1][y1+i] + self.grid[x1][y2-1-i] + self.grid[x2-1][y1+i] + self.grid[x2-1][y2-1-i]
                minFlips += min(fourVals, 4-fourVals)
            for i in range(1, m/2):
                fourVals = self.grid[x1+i][y1] + self.grid[x2-1-i][y1] + self.grid[x1+i][y2-1] + self.grid[x2-1-i][y2-1]
                minFlips += min(fourVals, 4-fourVals)
            if m % 2 == 1:
                twoVals = self.grid[x1+m/2][y1] + self.grid[x1+m/2][y2-1]
                if twoVals == 1:
                    numOnes += 1
                elif twoVals == 2:
                    numTwos += 1
            if n % 2 == 1:
                twoVals = self.grid[x1][y1+n/2] + self.grid[x2-1][y1+n/2]
                if twoVals == 1:
                    numOnes += 1
                elif twoVals == 2:
                    numTwos += 1
            minFlips += self.minFlipsBoundary(x1 + 1, x2 - 1, y1 + 1, y2 - 1, numTwos % 2, numOnes)
        return minFlips

    def minFlips(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        self.grid = grid
        minFlips = self.minFlipsBoundary(0, m, 0, n, 0, 0)
        return minFlips
        
