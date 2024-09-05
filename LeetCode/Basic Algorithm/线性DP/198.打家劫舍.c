int max(int a,int b)
{
    return a>b?a:b;
}
int dp[101];
int rob(int* nums, int numsSize) {
    if(numsSize==1)
    {
        return nums[0];
    }
    dp[0]=nums[0];
    dp[1]=max(dp[0],nums[1]);
    for(int i=2;i<numsSize;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[numsSize-1];
}
