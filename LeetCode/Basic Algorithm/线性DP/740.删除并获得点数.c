int hash[10001];
int dp[10001];
int max(int a,int b)
{
    return a>b?a:b;
}
int deleteAndEarn(int* nums, int numsSize) {
    memset(hash,0,sizeof(hash));
    for(int i=0;i<numsSize;i++)
    {
        hash[nums[i]]+=nums[i];
    }
    dp[0]=0;
    dp[1]=hash[1];
    for(int i=2;i<=10000;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+hash[i]);
    }
    return dp[10000];
}
