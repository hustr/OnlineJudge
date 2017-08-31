class Solution {
    // 动态规划，求数字和最小的路径
    public int minPathSum(int[][] grid) {
        if (grid == null || grid.length == 0) return 0;
        final int row = grid.length, col = grid[0].length;

        for (int i = 1; i < row; i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int i = 1; i < col; i++) {
            grid[0][i] += grid[0][i - 1];
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                grid[i][j] += (grid[i - 1][j] < grid[i][j - 1] ? grid[i - 1][j] : grid[i][j - 1]);
            }
        }
        return grid[row - 1][col - 1];
    }
}

