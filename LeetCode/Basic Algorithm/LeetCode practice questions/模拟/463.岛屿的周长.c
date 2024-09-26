const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int dfs(int x, int y, int** grid, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) {
        return 1;
    }
    if (grid[x][y] == 2) {
        return 0;
    }
    grid[x][y] = 2;
    int res = 0;
    for (int i = 0; i < 4; ++i) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        res += dfs(tx, ty, grid, n, m);
    }
    return res;
}

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize, m = gridColSize[0];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1) {
                ans += dfs(i, j, grid, n, m);
            }
        }
    }
    return ans;
}
