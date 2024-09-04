int subsetXORSum(int* nums, int numsSize) {
    int i,j,ans;
    int sum=0;
    for(i=0;i<(1<<numsSize);i++)
    {
        ans=0;
        for(j=0;j<numsSize;j++)
        {
            if(i&(1<<j))
            {
                ans^=nums[j];
            }
        }
        sum+=ans;
    }
    return sum;
}
