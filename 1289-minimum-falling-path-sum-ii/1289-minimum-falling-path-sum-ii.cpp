class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> memo(grid.size(), vector<int>(grid.size(), INT_MAX));
        for (int col = 0; col < grid.size(); col++) {
            memo[grid.size() - 1][col] = grid[grid.size() - 1][col];
        }
        for (int row = grid.size() - 2; row >= 0; row--) {
            for (int col = 0; col < grid.size(); col++) {
                int nextMinimum = INT_MAX;
                for (int nextRowCol = 0; nextRowCol < grid.size(); nextRowCol++) {
                    if (nextRowCol != col) {
                        nextMinimum = min(nextMinimum, memo[row + 1][nextRowCol]);
                    }
                }
                memo[row][col] = grid[row][col] + nextMinimum;
            }
        }
        int answer = INT_MAX;
        for (int col = 0; col < grid.size(); col++) {
            answer = min(answer, memo[0][col]);
        }
        return answer;
    }
};