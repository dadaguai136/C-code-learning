/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getAverages(int* nums, int numsSize, int k, int* returnSize){
    int size = k * 2 + 1;
    int *ret = (int *)malloc(sizeof(int) * numsSize);
    memset(ret, -1, sizeof(int) * numsSize);
    *returnSize = numsSize;
    long long sum = 0;
    int cnt = 0;
    if (size > numsSize) {
        return ret;        
    }
    for (int i = 0; i < size; i++) {
        sum += nums[i];
    }
    ret[k] = sum / size; 

    for (int i = k + 1; i < numsSize - k; i++) {
        sum -= nums[i - k - 1];
        sum += nums[i + k];
        ret[i] = sum / size;
    }


    return ret;
}




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getAverages(int* nums, int numsSize, int k, int* returnSize){
    int* returnArr = (int*)malloc(numsSize * sizeof(int));
    memset(returnArr, -1, numsSize * sizeof(int));
    *returnSize=numsSize;

    if(numsSize<2*k+1)
    {
        return returnArr;
    }
    long long sum=0;
    for(int i=0;i<2*k;i++)
    {
        sum+=nums[i];
    }

    int num2=0;
    for(int index=2*k;index<numsSize;index++)
    {
        if(index-2*k>=1)
        {
            num2=nums[index-2*k-1];
        }
        sum=sum+nums[index]-num2;
        returnArr[index-k]=sum/(2*k+1);
    }

    return returnArr;
}
