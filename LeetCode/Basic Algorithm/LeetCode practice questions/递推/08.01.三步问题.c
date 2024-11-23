

int waysToStep(int n){
    if(n<4)
    {
        return n==3?4:n;
    }
    int a=1,b=2,c=4;
    for(int i=4;i<=n;i++)
    {
        int temp=(a+b)%1000000007+c;
        a=b;
        b=c;
        c=temp%1000000007;
    }
    return c;
}
