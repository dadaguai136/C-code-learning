#define maxn 101
int sum[maxn];
int findMiddleIndex(int* nums, int numsSize) {
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




int findMiddleIndex(int* nums, int numsSize) {
    int total = 0;
    for (int i = 0; i < numsSize; ++i) {
        total += nums[i];
    }
    int sum = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (2 * sum + nums[i] == total) {
            return i;
        }
        sum += nums[i];
    }
    return -1;
}
