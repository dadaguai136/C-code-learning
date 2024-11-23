int maximum69Number (int num) {
    int stk[10];
    int top=0;
    while(num)
    {
        stk[top++]=num%10;
        num/=10;
    }
    for(int i=top-1;i>=0;i--)
    {
        if(stk[i]==6)
        {
            stk[i]=9;
            break;
        }
    }
    int sum=0;
    while(top--)
    {
        sum=sum*10+stk[top];
    }
    return sum;
}
