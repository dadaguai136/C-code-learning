/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int cmp(void const *pa,void const *pb)
 {
    return *(int *)pa-*(int *)pb;
 }
int** pairSums(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums,numsSize,sizeof(int),cmp);
    int left=0,right=numsSize-1;
    int **ret=(int **)malloc(sizeof(int*)*(numsSize/2));
    *returnColumnSizes=(int *)malloc(sizeof(int)*(numsSize/2));
    int size=0;
    while(left<right)
    {
        if(nums[left]+nums[right]==target)
        {
            ret[size]=(int *)malloc(sizeof(int)*2);
            ret[size][0]=nums[left],ret[size][1]=nums[right];
            (*returnColumnSizes)[size++]=2;
            left++,right--;
        }
        else if(nums[left]+nums[right]<target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    *returnSize=size;
    return ret;
}
