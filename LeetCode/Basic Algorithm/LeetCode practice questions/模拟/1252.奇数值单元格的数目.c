int oddCells(int m, int n, int** indices, int indicesSize, int* indicesColSize) {
    int i,j,r,c;
    int mat[110][110];
    int ans=0;
    memset(mat,0,sizeof(mat));
    for(i=0;i<indicesSize;i++)
    {
        r=indices[i][0];
        c=indices[i][1];
        for(j=0;j<n;j++)
        {
            ++mat[r][j];
        }
        for(j=0;j<m;j++)
        {
            ++mat[j][c];
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(mat[i][j]&1)
            {
                ans++;
            }
        }
    }
    return ans;
}
