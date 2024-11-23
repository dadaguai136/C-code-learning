int matrixScore(int** grid, int gridSize, int* gridColSize) {
    int n=gridSize,m=gridColSize[0];
    int ret=n*(1<<(m-1));
    for(int j=1;j<m;j++)
    {
        int nOnes=0;
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
            {
                nOnes+=grid[i][j];
            }
            else
            {
                nOnes+=(1-grid[i][j]);
            }
        }
        int k=fmax(nOnes,n-nOnes);
        ret+=k*(1<<(m-j-1));
    }
    return ret;
}
