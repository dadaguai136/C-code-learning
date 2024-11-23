int cmp(const void *a,const void *b)
{
    int vala=*(int *)a;
    int valb=*(int *)b;
    return vala>valb?1:-1;
}
int arrayPairSum(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmp);
    int ans=0;
    for(int i=0;i<numsSize;i+=2)
    {
        ans=ans+nums[i];
    }
    return ans;
}
