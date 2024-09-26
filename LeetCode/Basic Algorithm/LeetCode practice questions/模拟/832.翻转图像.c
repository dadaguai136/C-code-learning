/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int **MyMalloc(int r,int c,int *returnSize,int**returnColumnSizes)
 {
    int **ret=(int **)malloc(sizeof(int *)*r);
    *returnSize=r;
    *returnColumnSizes=(int *)malloc(sizeof(int)*r);
    for(int i=0;i<r;i++)
    {
        ret[i]=(int *)malloc(sizeof(int)*c);
        (*returnColumnSizes)[i]=c;
    }
    return ret;
 }
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    int n=imageSize;
    int m=imageColSize[0];
    int **ret=MyMalloc(m,n,returnSize,returnColumnSizes);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ret[i][j]=1-image[i][n-1-j];
        }
    }
    return ret;
}
