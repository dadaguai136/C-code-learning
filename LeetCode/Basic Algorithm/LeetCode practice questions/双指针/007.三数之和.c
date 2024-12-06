

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int cmp(const void *pa,const void *pb)
 {
    return *(int *)pa-*(int *)pb;
 }
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize=0;
    if(numsSize<3)
    {
        return NULL;
    }
    qsort(nums,numsSize,sizeof(int),cmp);
    int **ans=(int **)malloc(sizeof(int *)*numsSize*numsSize);
    *returnColumnSizes=(int *)malloc(sizeof(int)*numsSize*numsSize);
    int sum;
    int indexLeft=0;
    int indexMiddle=0;
    int indexRight=0;
    for(indexLeft=0;indexLeft<numsSize-2;indexLeft++)
    {
        if(nums[indexLeft]>0)
        {
            return ans;
        }
        if(indexLeft>0&&nums[indexLeft]==nums[indexLeft-1])
        {
            continue;
        }
        indexMiddle=indexLeft+1;
        indexRight=numsSize-1;
        while(indexMiddle<indexRight)
        {
            sum=nums[indexLeft]+nums[indexMiddle]+nums[indexRight];
            if(sum==0)
            {
                ans[*returnSize]=(int *)malloc(sizeof(int)*3);
                (*returnColumnSizes)[*returnSize]=3;
                ans[*returnSize][0]=nums[indexLeft];
                ans[*returnSize][1]=nums[indexRight];
                ans[*returnSize][2]=nums[indexMiddle];
                *returnSize+=1;
                while(indexMiddle<indexRight&&nums[indexMiddle]==nums[++indexMiddle]);
                while(indexMiddle<indexRight&&nums[indexRight]==nums[--indexRight]);
            }
            else if(sum>0)
            {
                indexRight--;
            }
            else
            {
                indexMiddle++;
            }
        }
    }
    return ans;
}
