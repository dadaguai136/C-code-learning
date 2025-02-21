#define maxn 30001
int sum[maxn];
int subarraysDivByK(int* nums, int numsSize, int k) {
    int hash[maxn];
    memset(hash,0,sizeof(hash));
    sum[0]=nums[0]%k;
    if(sum[0]<0)
    {
        sum[0]+=k;
    }
    for(int i=1;i<numsSize;i++)
    {
        sum[i]=(sum[i-1]+nums[i])%k;
        if(sum[i]<0)
        {
            sum[i]+=k;
        }
    }
    hash[0]=1;
    int ans=0;
    for(int j=0;j<numsSize;j++)
    {
        ans+=hash[sum[j]];
        hash[sum[j]]++;
    }
    return ans;
}
