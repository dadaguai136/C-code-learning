int f[1001];
int min(int a,int b)
{
    return a<b?a:b;
}
int minCostClimbingStairs(int* cost, int costSize) {
    f[0]=0;
    f[1]=0;
    for(int i=2;i<=costSize;i++)
    {
        f[i]=min(f[i-1]+cost[i-1],f[i-2]+cost[i-2]);
    }
    return f[costSize];
}
