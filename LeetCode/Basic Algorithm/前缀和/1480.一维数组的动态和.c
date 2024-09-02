int* runningSum(int* nums, int n, int* returnSize){
    *returnSize=n;
    int *ret=(int *)malloc(sizeof(int)*n);
    ret[0]=nums[0];
    for(int i=1;i<n;i++)
    {
        ret[i]=ret[i-1]+nums[i];
    }
    return ret;
}
