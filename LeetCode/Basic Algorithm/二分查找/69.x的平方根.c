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
    return (long long)val*val>x;
}
int mySqrt(int x) {
    int r;
    if(x==0||x==1)
    {
        return x;
    }
    r=binarySearch(0,x,x);
    return r-1;
}
