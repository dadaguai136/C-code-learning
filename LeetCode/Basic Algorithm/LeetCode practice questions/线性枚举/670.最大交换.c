void exchange(char *a,char *b)
{
    char c=*a;
    *a=*b;
    *b=c;
}
int maximumSwap(int num) {
    char arry[10];
    sprintf(arry,"%d",num);
    int n=strlen(arry);
    char maxIdx=n-1;
    int idx1=-1,idx2=-1;
    for(int i=n-1;i>=0;i--)
    {
        if(arry[i]>arry[maxIdx])
        {
            maxIdx=i;
        }
        else if(arry[i]<arry[maxIdx])
        {
            idx1=i;
            idx2=maxIdx;
        }
    }
    if(idx1>=0)
    {
        exchange(&arry[idx1],&arry[idx2]);
        {
            return atoi(arry);
        }
    }
    else
    {
        return num;
    }
}





void exchange(char *a,char *b)
{
    char c=*a;
    *a=*b;
    *b=c;
}
#define max(a,b) ((a)>(b)?(a):(b));
int maximumSwap(int num) {
    char arry[10];
    sprintf(arry,"%d",num);
    int n=strlen(arry);
    int maxNum=num;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            exchange(&arry[i],&arry[j]);
            maxNum=max(maxNum,atoi(arry));
            exchange(&arry[i],&arry[j]);
        }
    }
    return maxNum;
}
