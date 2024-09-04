int isGreen(int *a,int idx)
{
    return a[idx]<0;
}
int binarySearch(int l,int r,int *a)
{
    while(l+1<r)
    {
        int mid=l+(r-l)/2;
        if(isGreen(a,mid))
        {
            r=mid;
        }
        else
        {
            l=mid;
        }
    }
    return r;
}
int countNegatives(int** grid, int gridSize, int* gridColSize) {
    int n=gridSize;
    int m=gridColSize[0];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int pos=binarySearch(-1,m,grid[i]);
        ans+=m-pos;
    }
    return ans;
}
