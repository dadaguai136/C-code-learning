

int fib(int n){
    if(n==0)
    {
        return 0;
    }
    int a=1,b=1,c=1;
    while(n>2)
    {
        c=(a+b)%1000000007;
        a=b;
        b=c;
        n--;
    }
    return c;
}
