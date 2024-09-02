int sum[101];
int sumOddLengthSubarrays(int* a, int n)
{
    sum[0]=a[0];
    for(int i=1;i<n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int s=0;
    for(int len=1;len<=n;len+=2)
    {
        for(int l=0;l<n;l++)
        {
            int r=l+len-1;
            if(r>=n)
            {
                break;
            }
            if(l==0)
            {
                s+=sum[r];
            }
            else
            {
                s+=sum[r]-sum[l-1];
            }
        }
    }
    return s;
}
