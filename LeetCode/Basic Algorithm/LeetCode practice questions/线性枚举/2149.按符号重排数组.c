/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
    int *ans=(int *)malloc(sizeof(int)*numsSize);
    int index=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]>0)
        {
            ans[index]=nums[i];
            index+=2;
        }
    }
    index=1;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]<0)
        {
            ans[index]=nums[i];
            index+=2;
        }
    }
    *returnSize=numsSize;
    return ans;
}




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
    
    int* ans=(int*)malloc(sizeof(int)*200000);
    int s=0,o=1;
    int i=0;
    while(i<numsSize){
        if(nums[i]>0){
            ans[s]=nums[i];
            s=s+2;
        }
        
        if(nums[i]<0){
            ans[o]=nums[i];
            o+=2;
        }
        i++;
    }
    *returnSize=numsSize;
    return ans;
}
