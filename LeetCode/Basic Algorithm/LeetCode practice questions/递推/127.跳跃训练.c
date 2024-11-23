int trainWays(int num) {
    int a[101]={1,1};
    for(int i=2;i<=num;i++)
    {
        a[i]=a[i-1]+a[i-2];
        a[i]=a[i]%(int)(1e9+7);
    }
    return a[num];
}
