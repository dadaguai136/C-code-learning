/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int cmp(void const *pa,void const *pb)
 {
    return *(int *)pa-*(int *)pb;
 }
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    if(numsSize<3)
    {
        return NULL;
    }
    qsort(nums,numsSize,sizeof(int),cmp);
    int **ret=(int **)malloc(sizeof(int *)*numsSize*numsSize);
    *returnColumnSizes=(int *)malloc(sizeof(int)*numsSize*numsSize);
    *returnSize=0;
    int left=0,middle=0,right=0;
    for(left=0;left<numsSize-2;left++)
    {
        if(nums[left]>0)
        {
            return ret;
        }
        if(left>0&&nums[left]==nums[left-1])
        {
            continue;
        }
        middle=left+1;
        right=numsSize-1;
        while(middle<right)
        {
            if(nums[left]+nums[middle]+nums[right]==0)
            {
                ret[*returnSize]=(int *)malloc(sizeof(int)*3);
                (*returnColumnSizes)[*returnSize]=3;
                ret[*returnSize][0]=nums[left];
                ret[*returnSize][1]=nums[middle];
                ret[*returnSize][2]=nums[right];
                *returnSize+=1;
                while(middle<right&&nums[middle]==nums[++middle]);
                while(middle<right&&nums[right]==nums[--right]);
            }
            else if(nums[left]+nums[middle]+nums[right]<0)
            {
                middle++;
            }
            else
            {
                right--;
            }
        }
    }
    return ret;
}
