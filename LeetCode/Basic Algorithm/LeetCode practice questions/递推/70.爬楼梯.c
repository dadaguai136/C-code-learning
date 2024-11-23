int climbStairs(int n) {
    int a[46];
    a[0]=1;a[1]=1;
    for(int i=2;i<=n;i++)
    {
        a[i]=a[i-2]+a[i-1];
    }
    return a[n];
}
