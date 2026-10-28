#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // dp[i][j][k] will be true if an XOR sum of 'k' is reachable at cell (i, j)
        // Max possible XOR value for elements <= 1023 is 2047, so size 2048 is safe.
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(m, vector<bool>(2048, false)));
        
        // Base case: starting cell
        dp[0][0][grid[0][0]] = true;
        
        // Iterate through the grid sequentially (Left to Right, Top to Bottom)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 2048; k++) {
                    if (!dp[i][j][k]) continue; // If this XOR value isn't reachable here, skip
                    
                    // Move Down
                    if (i + 1 < n) {
                        dp[i + 1][j][k ^ grid[i + 1][j]] = true;
                    }
                    
                    // Move Right
                    if (j + 1 < m) {
                        dp[i][j + 1][k ^ grid[i][j + 1]] = true;
                    }
                }
            }
        }
        
        // Find the minimum reachable XOR value at the destination (n-1, m-1)
        for (int k = 0; k < 2048; k++) {
            if (dp[n - 1][m - 1][k]) {
                return k;
            }
        }
        
        return -1;
    }
};
