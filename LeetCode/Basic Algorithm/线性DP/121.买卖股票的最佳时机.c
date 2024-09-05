int maxProfit(int* prices, int n) {
    int maxp=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(prices[j]-prices[i]>maxp)
            {
                maxp=prices[j]-prices[i];
            }
        }
    }
    return maxp;
}
int maxProfit(int* prices, int n) {//”≈ªØ
    int maxp=0,min=prices[0];
    for(int i=1;i<n;i++)
    {
        if(prices[i]-min>maxp)
        {
            maxp=prices[i]-min;
        }
        if(min>prices[i])
        {
            min=prices[i];
        }
    }
    return maxp;
}
