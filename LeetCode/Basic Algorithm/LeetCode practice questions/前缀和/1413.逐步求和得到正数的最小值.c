bool valid(int startValue,const int *nums,int numsSize)
{
    for(int i=0;i<numsSize;i++)
    {
        startValue+=nums[i];
        if(startValue<=0)
        {
            return false;
        }
    }
    return true;
}
int minStartValue(int* nums, int numsSize) {
    int m=nums[0];
    for(int i=1;i<numsSize;i++)
    {
        m=fmin(m,nums[i]);
    }
    if(m>=0)
    {
        return 1;
    }
    int left=1,right=(-m)*numsSize+1;
    while(left<right)
    {
        int medium=(left+right)/2;
        if(valid(medium,nums,numsSize))
        {
            right=medium;
        }
        else
        {
            left=medium+1;
        }
    }
    return left;
}




int minStartValue(int* nums, int numsSize) {
    int sum=0,min=0;
    for(int i=0;i<numsSize;i++)
    {
        sum+=nums[i];
        min=fmin(sum,min);
    }
    return min*(-1)+1;
}




#define MIN(a, b) ((a) < (b) ? (a) : (b))
int minStartValue(int* nums, int numsSize){
    int accSum = 0, accSumMin = 0;
    for (int i = 0; i < numsSize; i++) {
        accSum += nums[i];
        accSumMin = MIN(accSumMin, accSum);
    }
    return -accSumMin + 1;
}
