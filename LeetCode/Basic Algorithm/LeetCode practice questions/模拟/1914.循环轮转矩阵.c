/* ��ÿһ������ݽ�����ת */ 
void deal(int **grid, int u, int d, int l, int r) {
    /* ��һ�� */
    int i;
    int tmp = grid[u][l];
    for (i = l + 1; i <= r; i++) {
        grid[u][i - 1] = grid[u][i];
    }
    /* ���һ�� */
    for (i = u + 1; i <= d; i++) {
        grid[i - 1][r] = grid[i][r];
    }
    /* ���һ�� */
    for (i = r - 1; i >= l; i--) {
        grid[d][i + 1] = grid[d][i];
    }
    /* ��һ�� */
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
    mm = fmin(m/2, n/2); /* ��Ҫ����Ĳ��� */
    
    for (i = 0; i < mm; i++) {
        kk = k % len;
        /* ÿһ���Ԫ��, ��Ҫ�ƶ�kk�� */
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
