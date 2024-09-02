int sum[1001];
int pivotInteger(int n) {
    sum[0]=0;
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+i;
    }
    for(int x=1;x<=n;x++)
    {
        if(sum[x]==sum[n]-sum[x-1])
        {
            return x;
        }
    }
    return -1;
}
