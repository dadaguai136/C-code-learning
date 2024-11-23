#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
    int * rowMax = (int *)malloc(sizeof(int) * gridSize);
    int * colMax = (int *)malloc(sizeof(int) * gridSize);
    memset(rowMax, 0, sizeof(int) * gridSize);
    memset(colMax, 0, sizeof(int) * gridSize);
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            rowMax[i] = MAX(rowMax[i], grid[i][j]);
            colMax[j] = MAX(colMax[j], grid[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            ans += MIN(rowMax[i], colMax[j]) - grid[i][j];
        }
    } 
    free(rowMax);
    free(colMax);
    return ans;
}
