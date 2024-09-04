bool isGreen(long long x,int num)
{
    return x*x>num;
}
bool isPerfectSquare(int num) {
    if(num==1)
    {
        return true;
    }
    long long l=-1,r=num;
    while(r-l>1)
    {
        int mid=l+(r-l)/2;
        if(isGreen(mid,num))
        {
            r=mid;
        }
        else
        {
            l=mid;
        }
    }
    return l*l==num;
}
