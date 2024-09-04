int binarySearch(int l,int r,int x)
{
    while(l+1<r)
    {
        int mid=l+(r-l)/2;
        if(isGreen(mid,x))
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
int isGreen(int val,int x)
{
    return isBadVersion(val);
}
int firstBadVersion(int n) {
    if(n==1)
    {
        return 1;
    }
    return binarySearch(0,n,-1);
}
