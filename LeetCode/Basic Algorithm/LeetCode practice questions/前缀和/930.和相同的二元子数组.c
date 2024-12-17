#define maxn 30001
int sum[maxn];
int numSubarraysWithSum(int* nums, int numsSize, int goal) {
    sum[0]=nums[0];
    for(int i=1;i<numsSize;i++)
    {
        sum[i]=sum[i-1]+nums[i];
    }
    int hash[maxn*2];
    memset(hash,0,sizeof(hash));
    hash[goal]=1;
    int ans=0;
    for(int j=0;j<numsSize;j++)
    {
        ans+=hash[sum[j]];
        hash[goal+sum[j]]++;
    }
    return ans;
}




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
