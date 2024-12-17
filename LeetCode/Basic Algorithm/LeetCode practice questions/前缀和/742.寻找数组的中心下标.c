#define maxn 10001
int sum[maxn];
int pivotIndex(int* nums, int numsSize) {
    sum[0]=nums[0];
    for(int i=1;i<numsSize;i++)
    {
        sum[i]=sum[i-1]+nums[i];
    }
    if(sum[0]==sum[numsSize-1])
    {
        return 0;
    }
    int ans=-1;
    for(int i=1;i<numsSize;i++)
    {
        if(sum[i-1]==sum[numsSize-1]-sum[i])
        {
            ans=i;
            break;
        }
    }
    return ans;
}
