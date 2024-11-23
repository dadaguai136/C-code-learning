#define Max(a,b) ((a)>(b)?(a):(b))

int maxRotateFunction(int* nums, int numsSize){
    int f=0,sum=0;
    for(int i=0;i<numsSize;i++)
    {
        f+=nums[i]*i;
        sum+=nums[i];
    }
    int arr=f;
    for(int i=numsSize-1;i>0;i--)
    {
        f+=sum-nums[i]*numsSize;
        arr=Max(f,arr);
    }
    return arr;
}
