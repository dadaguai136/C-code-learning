#define MIN(a, b) ((a) < (b) ? (a) : (b))

int** restoreMatrix(int* rowSum, int rowSumSize, int* colSum, int colSumSize, int* returnSize, int** returnColumnSizes) {
    int n = rowSumSize, m = colSumSize;
    int **matrix = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * m);
        memset(matrix[i], 0, sizeof(int) * m);
    }
    int i = 0, j = 0;
    while (i < n && j < m) {
        int v = MIN(rowSum[i], colSum[j]);
        matrix[i][j] = v;
        rowSum[i] -= v;
        colSum[j] -= v;
        if (rowSum[i] == 0) {
            ++i;
        }
        if (colSum[j] == 0) {
            ++j;
        }
    }
    *returnSize = n;
    *returnColumnSizes = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = m;
    }
    return matrix;
}



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** restoreMatrix(int* rowSum, int rowSumSize, int* colSum, int colSumSize, int* returnSize, int** returnColumnSizes){
    int **ret=(int**)malloc(sizeof(int*)*rowSumSize);
    for(int i=0;i<rowSumSize;i++){
        ret[i]=(int*)malloc(sizeof(int)*colSumSize);
        for(int j=0;j<colSumSize;j++){
            ret[i][j]=-1;
        }
    }
    for(int i=0;i<rowSumSize;i++){
        for(int j=0;j<colSumSize;j++){
            int minn=rowSum[i]>colSum[j]?colSum[j]:rowSum[i];
            rowSum[i]-=minn;
            colSum[j]-=minn;
            ret[i][j]=minn;
        }
    }
    *returnSize=rowSumSize;
    *returnColumnSizes=(int*)malloc(sizeof(int)*rowSumSize);
    for(int i=0;i<rowSumSize;i++){
        (*returnColumnSizes)[i]=colSumSize;
    }
    return ret;
}
