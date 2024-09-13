bool reorderedPowerOf2(int n) {
    int hash[10];
    memset(hash,0,sizeof(hash));
    while(n!=0)
    {
        hash[n%10]++;
        n/=10;
    }
    int arry[31][10]={0};
    for(int i=0;i<=30;i++)
    {
        int count=1<<i;
        while(count!=0)
        {
            arry[i][count%10]++;
            count/=10;
        }
    }
    for(int i=0;i<=30;i++)
    {
        if(!memcmp(arry[i],hash,sizeof(hash)))
        {
            return true;
        }
    }
    return false;
}
