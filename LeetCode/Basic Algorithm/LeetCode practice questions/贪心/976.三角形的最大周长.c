int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int largestPerimeter(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmp);
    for(int i=numsSize-1;i>=2;i--)
    {
        int c=nums[i];
        int b=nums[i-1];
        int a=nums[i-2];
        if(a+b>c)
        {
            return a+b+c;
        }
    }
    return 0;
}
