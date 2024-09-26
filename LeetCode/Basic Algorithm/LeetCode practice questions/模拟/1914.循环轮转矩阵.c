/* 对每一层的数据进行轮转 */ 
void deal(int **grid, int u, int d, int l, int r) {
    /* 第一行 */
    int i;
    int tmp = grid[u][l];
    for (i = l + 1; i <= r; i++) {
        grid[u][i - 1] = grid[u][i];
    }
    /* 最后一列 */
    for (i = u + 1; i <= d; i++) {
        grid[i - 1][r] = grid[i][r];
    }
    /* 最后一行 */
    for (i = r - 1; i >= l; i--) {
        grid[d][i + 1] = grid[d][i];
    }
    /* 第一列 */
    for (i = d - 1; i >= u + 1; i--) {
        grid[i + 1][l] = grid[i][l];
    }
    grid[u + 1][l] = tmp;
}

int** rotateGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){
    int m = gridSize;
    int n = gridColSize[0];
    int i, j, kk, u, d, l, r, len, mm;
    *returnColumnSizes = gridColSize;
    *returnSize = gridSize;
    len = 2 * n + 2 * (m - 2);
    
    u = 0;
    d = m - 1;
    l = 0;
    r = n - 1;
    mm = fmin(m/2, n/2); /* 需要处理的层数 */
    
    for (i = 0; i < mm; i++) {
        kk = k % len;
        /* 每一层的元素, 需要移动kk次 */
        for (j = 0; j < kk; j++) {
            deal(grid, u, d, l, r);
        }
        u++;
        d--;
        l++;
        r--;
        len -= 8;
    }
    return grid;
}
