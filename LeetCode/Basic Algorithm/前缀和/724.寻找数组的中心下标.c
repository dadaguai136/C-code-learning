int pivotIndex(int* nums, int n) {
    int *sum=(int *)malloc(sizeof(int)*n);
    sum[0]=nums[0];
    for(int i=1;i<n;i++)
    {
        sum[i]=sum[i-1]+nums[i];
    }
    if(sum[0]==sum[n-1])
    {
        return 0;
    }
    int ans=-1;
    for(int i=1;i<n;i++)
    {
        if(sum[i-1]==sum[n-1]-sum[i]) 
        {
            ans=i;
            break;
        }
    }
    return ans;
}
