bool isGreen(long long x,int n)
{
    return x*(x+1)/2>n;
}

int arrangeCoins(int n){
    long long l=-1;
    long long r=(long long)n+1;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        if(isGreen(mid,n))
        {
            r=mid;
        }
        else
        {
            l=mid;
        }
    }
    return l;
}
