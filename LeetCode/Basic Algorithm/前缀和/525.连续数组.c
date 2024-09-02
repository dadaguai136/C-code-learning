int sum[100002];
int findMaxlength(int *a,int n)
{
	sum[0]=0;
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i-1];
	}
	for(int len=n;len>=0;len--)
	{
		for(int l=1;l<=n;l++)
		{
			int r=l+len-1;
			if(r>n)
			{
				break;
			}
			if(2*(sum[r]-sum[l-1])==len)
			{
				return len;
			}
		}
	}
	return 0;
}
//ÓÅ»¯
#define base 200000
int sum[100002];
int hash[200005+base];
int findMaxLength(int* nums, int n) {
    sum[0]=0;
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+nums[i-1];
    }
    memset(hash,-1,sizeof(hash));
    int max=0;
    for(int l=1;l<=n;l++)
    {
        int y=2*sum[l]-l;
        if(hash[y+base]!=-1)
        {
            int left=hash[y+base];
            if(l-left+1>max)
            {
                max=l-left+1;
            }
        }
        int x=2*sum[l-1]-(l-1);
        if(hash[x+base]==-1)
        {
            hash[x+base]=l;
        }
    }
    return max;
    //len==r-l+1
    //2*(sum[r]-sum[l-1])==r-l+1
    //2*sum[r]-r==2*sum[l-1]-(l-1)
}
