int hash[60001];
int sum[30001];
int numSubarraysWithSum(int* a, int n, int goal){
    memset(hash,0,sizeof(hash));
    ++hash[goal];
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            sum[i]=a[i];
        }
        else
        {
            sum[i]=sum[i-1]+a[i];
        }
    }
    int ans=0;
    for(int j=0;j<n;j++)
    {
        ans+=hash[sum[j]];
        hash[sum[j]+goal]++;
    }
    return ans;
}
/*
sum[r]-sum[l-1]==goal
sum[r]=goal+sum[l-1]
goal+sum[i]->hash
*/
