#define abs(a) (((a) > 0) ? (a) : (-(a)))

int cmp(const void* v1, const void* v2) {
    return abs(*(int*)v2) - abs(*(int*)v1);
}

int largestSumAfterKNegations(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);
    for(int i=0;i<numsSize;i++){
        if(k>0&&nums[i]<0){
            nums[i]*=-1;
            k--;
        }
    }
    if(k%2==1){
        nums[numsSize-1]*=-1;
    }
    int result=0;
    for(int i=0;i<numsSize;i++){
        result+=nums[i];
    }
    return result;
}






int cmp(const void *pa,const void *pb)
{
    return *(int *)pa-*(int *)pb;
}
int largestSumAfterKNegations(int* nums, int numsSize, int k) {
    qsort(nums,numsSize,sizeof(int),cmp);
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]<0)
        {
            nums[i]=-1*nums[i];
            k--;
        }
        if(k==0)
        {
            break;
        }
    }
    if(k>0)
    {
        qsort(nums,numsSize,sizeof(int),cmp);
    }
    for(int i=0;i<k;i++)
    {
        nums[0]=-1*nums[0];
    }
    int sum=0;
    for(int i=0;i<numsSize;i++)
    {
        sum+=nums[i];
    }
    return sum;
}
